/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** drawing lists
*/

#include "my_defender.h"

int get_type(enum tower_type type)
{
    switch (type) {
    case archer:
        return (2);
    case mage:
        return (3);
    case freeze:
        return (4);
    case cancrelat:
        return (5);
    default:
        return (2);
    }
}

void draw_opponent_list(sfRenderWindow *win, scene_t *scene)
{
    opponent_t *opp = scene->opp;

    while (opp != NULL) {
        sfSprite_setPosition(scene->objs[OPPONENT_INDEX]->sprite, opp->pos);
        sfRenderWindow_drawSprite(win, scene->objs[OPPONENT_INDEX]->sprite, 0);
        opp = opp->next;
    }
}

void draw_circle(sfRenderWindow *win, scene_t *scene, int index, tower_t *tow)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {tow->pos.x - tow->range + TOWER_WIDTH / 2,
		      tow->pos.y - tow->range + TOWER_HEIGHT / 2};
    sfColor color = {209, 241, 255, 0.3 * 255};
    sfVector2i posi = sfMouse_getPositionRenderWindow(win);
    sfVector2f posf = {posi.x, posi.y};

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, tow->range);
    if (tow->pos.x <= posf.x - 25 + tow->wid &&
        tow->pos.y <= posf.y - 35 + tow->hei &&
        tow->pos.x + tow->wid >= posf.x - 25 &&
        tow->pos.y + tow->hei >= posf.y - 35)
        sfRenderWindow_drawCircleShape(win, circle, NULL);
}

void draw_tower_list(sfRenderWindow *win, scene_t *scene)
{
    tower_t *tower = scene->tower;
    int index = 0;

    while (tower != NULL) {
        index = get_type(tower->type);
        draw_circle(win, scene, index, tower);
        sfSprite_setPosition(scene->objs[index]->sprite, tower->pos);
        sfRenderWindow_drawSprite(win, scene->objs[index]->sprite, 0);
        tower = tower->next;
    }
}
