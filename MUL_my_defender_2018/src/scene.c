/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** scene
*/

#include "my_defender.h"

int play(sfRenderWindow *win, scene_t *scene)
{
    scene->play = 1;
}

int credits(sfRenderWindow *win, scene_t *scene)
{
    sfVector2f pos = {495, 600};
    sfVector2f sz = {300, 50};

    sfRectangleShape_setPosition(scene->buttons[0]->rect, pos);
    init_button(scene->buttons[0], "Back", (sfVector2f){495, 650}, sz);
    scene->buttons[0]->callback = &back_to_menu;
    scene->buttons[0]->size = 42;
    scene->buttons[1] = 0;
    scene->objs[0] = create_object("img/creds.png", (sfVector2f){0, 0});
    scene->messages = malloc(sizeof(sfText *) * 3);
    if (!scene->messages)
        return (84);
    scene->messages[0] = create_text("Credits", 130, (sfVector2f){470, 100});
    scene->messages[1] = create_text(CREDS, 40, (sfVector2f){450, 275});
    scene->messages[2] = NULL;
}

int exit_game(sfRenderWindow *win, scene_t *scene)
{
    sfRenderWindow_close(win);
}

void draw_scene(sfRenderWindow *win, scene_t *scene)
{
    sfRenderWindow_clear(win, sfBlack);
    for (int i = 0; scene->objs[i]; ++i)
        sfRenderWindow_drawSprite(win, scene->objs[i]->sprite, 0);
    for (int i = 0; scene->buttons[i]; ++i)
        display_button(win, *scene->buttons[i]);
    for (int i = 0; scene->messages[i]; ++i)
        sfRenderWindow_drawText(win, scene->messages[i], 0);
}

void draw_game_scene(sfRenderWindow *win, scene_t *scene)
{
    game_object_t *tmp = create_object(OPPONENT, START_POS);
    char *money = scene->money == 0 ? "0\0" : my_getnbr(scene->money);

    sfRenderWindow_clear(win, sfBlack);
    for (int i = 0; scene->objs[i + 1]; ++i)
        sfRenderWindow_drawSprite(win, scene->objs[i]->sprite, 0);
    draw_opponent_list(win, scene);
    draw_tower_list(win, scene);
    display_bullets(win, scene);
    for (int i = 0; scene->buttons[i]; ++i)
        display_button(win, *scene->buttons[i]);
    for (int i = 0; scene->messages[i]; ++i)
        sfRenderWindow_drawText(win, scene->messages[i], 0);
    sfText_setString(scene->messages[4], money);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        pause_game(win, scene);
}
