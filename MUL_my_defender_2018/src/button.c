/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** button func
*/

#include "my_defender.h"

void display_button(sfRenderWindow *win, button_t button)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/cloisterblack_font.ttf");
    sfVector2f pos = sfRectangleShape_getPosition(button.rect);
    sfVector2f size = sfRectangleShape_getSize(button.rect);
    int midx = pos.x + size.x / 2 - my_strlen(button.text) * 8;
    int midy = pos.y + size.y / 2 - 30;

    if (!txt || !font) {
        my_putstr("Error: cannot create text\n");
        return;
    }
    sfRenderWindow_drawRectangleShape(win, button.rect, NULL);
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, button.size);
    sfText_setString(txt, button.text ? button.text : "(null)");
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, (sfVector2f){midx, midy});
    sfRenderWindow_drawText(win, txt, 0);
    sfText_destroy(txt);
    sfFont_destroy(font);
}

int button_is_clicked(button_t button, sfVector2i click_position)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(button.rect);
    sfVector2f rect_sz = sfRectangleShape_getSize(button.rect);
    int max_x = rect_pos.x + rect_sz.x;
    int max_y = rect_pos.y + rect_sz.y;

    if (click_position.x >= rect_pos.x && click_position.x <= max_x &&
        click_position.y >= rect_pos.y && click_position.y <= max_y) {
        return (1);
    } else
        return (0);
}

int is_position_valid(tower_t *tow, sfVector2f posf)
{
    if (tow->pos.x <= posf.x - 25 + tow->wid &&
        tow->pos.y <= posf.y - 35 + tow->hei &&
        tow->pos.x + tow->wid >= posf.x - 25 &&
        tow->pos.y + tow->hei >= posf.y - 35)
        return (1);
    return (0);
}

int check_btn_click(sfRenderWindow *win, scene_t *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f posf = {pos.x, pos.y};
    tower_t *tow = scene->tower;

    for (int i = 0; scene->buttons[i]; i++) {
        if (button_is_clicked(*scene->buttons[i], pos)) {
            scene->buttons[i]->callback(win, scene);
            return (1);
        }
    }
    while (tow) {
        if (is_position_valid(tow, posf) == 1)
            return (1);
        tow = tow->next;
    }
    posf.x -= 25;
    posf.y -= 35;
    if (scene->cur_type && is_tower_valid(posf, scene) == 1)
        scene->tower = add_tower(scene->tower, scene->cur_type, posf);
}

void init_button(button_t *btn, char *txt, sfVector2f pos, sfVector2f size)
{
    sfColor grey = {120, 120, 120, 120};

    btn->rect = sfRectangleShape_create();
    if (!btn || !btn->rect)
        return;
    sfRectangleShape_setPosition(btn->rect, pos);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setFillColor(btn->rect, grey);
    grey.a += 50;
    sfRectangleShape_setOutlineColor(btn->rect, grey);
    sfRectangleShape_setOutlineThickness(btn->rect, 6);
    btn->text = txt;
}
