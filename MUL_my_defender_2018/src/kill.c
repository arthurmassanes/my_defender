/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** killing ennemies
*/

#include "my_defender.h"

int is_collid(sfIntRect rect1, sfIntRect rect2,
                sfVector2f pos1, sfVector2f pos2)
{
    if (pos2.x >= pos1.x && pos2.x <= pos1.x + rect1.width
        || pos2.x + rect2.width >= pos1.x &&
        pos2.x + rect2.width <= pos1.x + rect1.width) {
        if (pos2.y >= pos1.y && pos2.y <= pos1.y + rect1.height ||
            pos2.y + rect2.height >= pos1.y &&
            pos2.y + rect2.height <= pos1.y + rect1.height)
            return (1);
        else
            return (0);
    } else
        return (0);
}

void make_damage(opponent_t *opp, tower_t *tow)
{
    opp->life -= tow->damage;
    if (tow->type == freeze) {
        opp->speed.x /= 2;
        opp->speed.y /= 2;
    } else if (tow->type == mage) {
        opp->life -= tow->damage;
        if (opp->previous)
            opp->previous->life -= tow->damage;
        opp->life = opp->life;
        if (opp->next)
            opp->next->life -= tow->damage;
    }
}

void kill_opponent(tower_t *tow, scene_t *scene)
{
    sfIntRect bull_rect = {0, 0, 15, 15};
    sfIntRect opp_rect = {0, 0, 50, 70};
    int collide;
    opponent_t *opp = scene->opp;

    if (!tow || !tow->bullet)
        return;
    else if (tow->bullet->pos.x <= 0 || tow->bullet->pos.y <= 0 ||
             tow->bullet->pos.x >= 1200 || tow->bullet->pos.y >= 800) {
        tow->bullet = 0;
        return;
    }
    while (opp) {
        if (is_collid(opp_rect, bull_rect, opp->pos, tow->bullet->pos) == 1) {
            tow->bullet = 0;
            make_damage(opp, tow);
            tow = tow->next;
            return;
        }
        opp = opp->next;
    }
}
