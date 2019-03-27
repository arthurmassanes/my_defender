/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** menu
*/

#include "my_defender.h"

int back_to_menu(sfRenderWindow *win, scene_t *scene)
{
    sfVector2f pos = {360, 100};
    sfVector2f sz = {300, 50};

    scene->buttons = create_menu_buttons();
    scene->objs[0] = create_object(MENU_IMG, (sfVector2f){0, 0});
    scene->objs[1] = 0;
    scene->messages[0] = create_text(GAME, 130, pos);
    scene->messages[1] = 0;
}

sfMusic *start_music(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    if (!music)
        return (NULL);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

button_t **create_menu_buttons(void)
{
    sfVector2f pos = {495, 350};
    button_t **buttons = malloc(sizeof(button_t *) * 7);

    for (int i = 0; i < 7; i++)
        buttons[i] = malloc(sizeof(button_t));
    init_button(buttons[0], "Play", pos, (sfVector2f){300, 50});
    pos.y += 75;
    init_button(buttons[1], "Credits", pos, (sfVector2f){300, 50});
    pos.y += 75;
    init_button(buttons[2], "Options", pos, (sfVector2f){300, 50});
    pos.y += 75;
    init_button(buttons[3], "Exit", pos, (sfVector2f){300, 50});
    buttons[0]->callback = play;
    buttons[1]->callback = credits;
    buttons[2]->callback = &option;
    buttons[3]->callback = exit_game;
    buttons[4] = 0;
    for (int i = 0; i < 4 && buttons[i]; ++i)
        buttons[i]->size = 42;
    return (buttons);
}

void init_scene(scene_t *scene)
{
    scene->fps = 24;
    scene->play = 0;
    scene->tower = NULL;
    scene->cur_type = 0;
}

scene_t *create_menu_scene(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return (NULL);
    scene->objs = malloc(sizeof(game_object_t) * 2);
    scene->messages = malloc(sizeof(sfText *) * 3);
    for (int i = 0; i < 2; ++i)
        scene->objs[i] = malloc(sizeof(game_object_t));
    scene->objs[0] = create_object(MENU_IMG, (sfVector2f){0, 0});
    scene->objs[1] = 0;
    scene->shot = create_sound("audio/shoot.ogg", 100);
    scene->buttons = create_menu_buttons();
    scene->messages[0] = create_text(GAME, 130, (sfVector2f){360, 100});
    scene->messages[1] = NULL;
    if (!scene->messages[0] || !scene->buttons[0] || !scene->objs[0])
        return (NULL);
    scene->theme = start_music(THEME);
    scene->volume = sfMusic_getVolume(scene->theme);
    init_scene(scene);
    return (scene);
}
