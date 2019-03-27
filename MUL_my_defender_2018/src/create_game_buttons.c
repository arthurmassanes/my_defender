/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main game buttons
*/

#include "my_defender.h"

void set_buttons_color_size(button_t **buttons)
{
    sfColor button_color = {120, 200, 20, 1};

    for (int i = 0; i != 4 && buttons[i]; ++i) {
        button_color.a = 120;
        sfRectangleShape_setFillColor(buttons[i]->rect, button_color);
        button_color.a += 50;
        sfRectangleShape_setOutlineColor(buttons[i]->rect, button_color);
    }
    for (int i = 0; i != 4 && buttons[i]; ++i)
        buttons[i]->size = 38;
    buttons[4]->size = 42;
}

void add_button_callback(button_t **buttons)
{
    buttons[0]->callback = &prepare_archer;
    buttons[1]->callback = &prepare_mage;
    buttons[2]->callback = &prepare_freeze;
    buttons[3]->callback = &prepare_cancrelat;
    buttons[4]->callback = &pause_game;
}

button_t **create_game_buttons(button_t **buttons)
{
    sfVector2f pos = {200, 5};

    for (int i = 0; i < 6; i++)
        buttons[i] = malloc(sizeof(button_t));
    init_button(buttons[0], "archer $150", pos, (sfVector2f){175, 30});
    pos.x += 220;
    init_button(buttons[1], "mage $100", pos, (sfVector2f){175, 30});
    pos.x += 220;
    init_button(buttons[2], "freeze $50", pos, (sfVector2f){175, 30});
    pos.x += 220;
    init_button(buttons[3], "fire $2500", pos, (sfVector2f){220, 30});
    pos.x = 10;
    pos.y = 10;
    set_buttons_color_size(buttons);
    init_button(buttons[4], "pause", pos, (sfVector2f){150, 20});
    add_button_callback(buttons);
    buttons[5] = NULL;
    return (buttons);
}
