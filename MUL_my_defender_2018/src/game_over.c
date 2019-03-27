/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game over functions
*/

#include "my_defender.h"

sfText **create_last_scene_messages(int wave)
{
    sfText **messages = malloc(sizeof(sfText *) * 5);

    if (!messages)
        return (0);
    messages[0] = create_text("GAME OVER!", 100, (sfVector2f){300, 100});
    messages[1] = create_text(LAST_MSG, 55, (sfVector2f){200, 300});
    messages[2] = create_text(my_getnbr(wave), 100, (sfVector2f){750, 275});
    messages[3] = create_text("[ESC] Exit", 45, (sfVector2f){850, 600});
    messages[4] = 0;
    sfText_setColor(messages[2], sfBlack);
    return (messages);
}

game_object_t **create_last_scene_objects(void)
{
    game_object_t **objs = malloc(sizeof(game_object_t) * 2);

    if (!objs)
        return (0);
    objs[0] = create_object(GAME_OVER, (sfVector2f){0, 0});
    objs[1] = 0;
    sfSprite_setTextureRect(objs[0]->sprite, (sfIntRect){0, 0, 1280, 800});
    return (objs);
}

scene_t *create_last_scene(int wave)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return (0);
    scene->clock = sfClock_create();
    scene->objs = create_last_scene_objects();
    scene->messages = create_last_scene_messages(wave);
    if (!scene->objs || !scene->buttons || !scene->messages)
        return (0);
    scene->buttons = malloc(sizeof(button_t *));
    scene->buttons = 0;
    scene->opp = malloc(sizeof(opponent_t));
    scene->opp = 0;
    scene->castle_hp = 0;
    scene->theme = sfMusic_createFromFile("audio/game_over.ogg");
    sfMusic_play(scene->theme);
    init_main_scene(scene);
    return (scene);
}

int game_over(sfRenderWindow *win, scene_t *scene)
{
    scene_t *last_scene = create_last_scene(scene->wave);

    if (!last_scene)
        return (EXIT_ERROR);
    destroy_scene(scene);
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_drawSprite(win, last_scene->objs[0]->sprite, 0);
        for (int i = 0; last_scene->messages[i]; ++i)
            sfRenderWindow_drawText(win, last_scene->messages[i], 0);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win);
        sfRenderWindow_display(win);
        poll_event(win);
    }
    for (int i = 0; last_scene->messages[i]; ++i)
        sfText_destroy(last_scene->messages[i]);
    destroy_game_object(last_scene->objs[0]);
    sfMusic_destroy(last_scene->theme);
    return (0);
}
