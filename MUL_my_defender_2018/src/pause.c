/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonctions to pause the game
*/

#include "my_defender.h"

int resume(sfRenderWindow *win, scene_t *scene)
{
    destroy_scene(scene);
    scene->play = 0;
}

int menu(sfRenderWindow *win, scene_t *scene)
{
    destroy_scene(scene);
    scene->play = 2;
}

button_t **create_pause_button(void)
{
    sfVector2f pos = {495, 350};
    button_t **buttons = malloc(sizeof(button_t *) * 4);

    for (int i = 0; i < 3; i++)
        buttons[i] = malloc(sizeof(button_t));
    init_button(buttons[0], "Resume", pos, (sfVector2f){300, 50});
    pos.y += 75;
    init_button(buttons[1], "Menu", pos, (sfVector2f){300, 50});
    pos.y += 75;
    init_button(buttons[2], "Exit", pos, (sfVector2f){300, 50});
    buttons[0]->callback = &resume;
    buttons[1]->callback = &menu;
    buttons[2]->callback = &exit_pause;
    buttons[3] = 0;
    for (int i = 0; i < 4 && buttons[i]; ++i)
        buttons[i]->size = 42;
    return (buttons);
}

scene_t *create_pause_scene(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return (NULL);
    scene->objs = malloc(sizeof(game_object_t) * 2);
    scene->messages = malloc(sizeof(sfText *) * 2);
    scene->objs[0] = create_object(PAUSE_MENU, (sfVector2f){0, 0});
    scene->objs[1] = 0;
    scene->buttons = create_pause_button();
    scene->messages[0] = create_text("Pause", 130, (sfVector2f){360, 100});
    scene->messages[1] = NULL;
    if (!scene->messages[0] || !scene->buttons[0] || !scene->objs[0])
        return (NULL);
    scene->theme = NULL;
    scene->tower = NULL;
    scene->shot = create_sound("audio/shoot.ogg", 100);
    scene->cur_type = NULL;
    return (scene);
}

int pause_game(sfRenderWindow *win, scene_t *scene)
{
    scene_t *pause = create_pause_scene();

    pause->play = 1;
    while (pause->play == 1 && sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlue);
        draw_scene(win, pause);
        poll_event(win);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            check_btn_click(win, pause);
        sfRenderWindow_display(win);
    }
    scene->cur_type = NULL;
    scene->play = pause->play;
}
