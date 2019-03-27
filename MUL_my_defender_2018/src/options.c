/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonction for the option scene
*/
#include "my_defender.h"

void create_fps_buttons(button_t **buttons)
{
    sfVector2f size = {70, 50};

    init_button(buttons[5], "+", (sfVector2f){630, 450}, size);
    init_button(buttons[6], "-", (sfVector2f){720, 450}, size);
    buttons[5]->callback = increase_fps;
    buttons[6]->callback = decrease_fps;
    for (int i = 0; i != 7 && buttons[i]; ++i)
        buttons[i]->size = 37;
}

button_t **create_option_button(void)
{
    sfVector2f sz = {300, 50};
    sfVector2f sz_sd = {140, 50};
    button_t **buttons = malloc(sizeof(button_t *) * 9);

    for (int i = 0; i < 9; i++)
        buttons[i] = malloc(sizeof(button_t));
    init_button(buttons[0], "Back", (sfVector2f){495, 650}, sz);
    init_button(buttons[1], "Sound -", (sfVector2f){495, 575}, sz_sd);
    init_button(buttons[2], "Sound +", (sfVector2f){655, 575}, sz_sd);
    init_button(buttons[3], "Music on", (sfVector2f){495, 375}, sz);
    init_button(buttons[4], "Music off", (sfVector2f){495, 300}, sz);
    buttons[0]->callback = &back_to_menu;
    buttons[1]->callback = sound_low;
    buttons[2]->callback = sound_up;
    buttons[3]->callback = sound_on;
    buttons[4]->callback = sound_off;
    create_fps_buttons(buttons);
    buttons[7] = 0;
    return (buttons);
}

int option(sfRenderWindow *win, scene_t *scene)
{
    char *num_fps = my_getnbr(scene->fps);

    scene->buttons = create_option_button();
    scene->objs[0] = create_object(OPTIONS, (sfVector2f){0, 0});
    scene->messages = malloc(sizeof(sfText *) * 4);
    if (!scene->messages)
        return (84);
    scene->messages[0] = create_text("Options", 130, (sfVector2f){470, 100});
    scene->messages[1] = create_text("FPS:", 30, (sfVector2f){495, 450});
    scene->messages[2] = create_text(num_fps, 30, (sfVector2f){580, 450});
    scene->messages[3] = 0;
}
