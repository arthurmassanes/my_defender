/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** firing bullets
*/

#include "my_defender.h"

int get_closest_opp_index(tower_t *tower, opponent_t *opp)
{
    opponent_t *tmp = opp;
    int closest_opp = 1000000;
    int closest_index = -1;
    int cur_opp = 0;
    int index = 0;
    int range = my_pow(tower->range, 2);
    int posx;
    int posy;

    for (index = 0; tmp; tmp = tmp->next, index++) {
        posx = my_pow((tower->pos.x) - tmp->pos.x, 2) + 35;
        posy = my_pow((tower->pos.y) - tmp->pos.y, 2) + 45;
        cur_opp =  posx + posy;
        if ((cur_opp < closest_opp) && cur_opp <= range) {
            closest_index = index;
            closest_opp = cur_opp;
        }
    }
    return (closest_index);
}

opponent_t *get_closest_opp(opponent_t *opp, int index)
{
    int i = 0;
    opponent_t *tmp = opp;

    while (i != index) {
        tmp = tmp->next;
        ++i;
    }
    return (tmp);
}

void create_bullet(scene_t *scene, tower_t *tmp, opponent_t *opp)
{
    int opp_index;
    opponent_t *opp_tmp = opp;
    opponent_t *closest;
    bullet_t *bullet = malloc(sizeof(bullet_t));

    opp_index = get_closest_opp_index(tmp, opp_tmp);
    if (opp_index == -1 || !bullet)
        return;
    sfSound_play(scene->shot->snd);
    closest = get_closest_opp(opp, opp_index);
    bullet->pos.x = tmp->pos.x;
    bullet->pos.y = tmp->pos.y;
    bullet->type = tmp->type;
    bullet->speed.x = (closest->pos.x - tmp->pos.x) / 20;
    bullet->speed.y = (closest->pos.y - tmp->pos.y) / 20;
    tmp->bullet = bullet;
}

void display_bullets(sfRenderWindow *win, scene_t *scene)
{
    tower_t *tmp = scene->tower;

    while (tmp != NULL) {
        if (tmp->bullet != NULL) {
            tmp->bullet->pos.x += tmp->bullet->speed.x;
            tmp->bullet->pos.y += tmp->bullet->speed.y;
            sfSprite_setPosition(scene->objs[6]->sprite, tmp->bullet->pos);
            sfRenderWindow_drawSprite(win, scene->objs[6]->sprite, 0);
        }
    tmp = tmp->next;
    }
}

void fire_bullets(sfRenderWindow *win, scene_t *scene)
{
    tower_t *tmp = scene->tower;
    sfVector2f pos;

    if (!tmp)
        return;
    while (tmp) {
        kill_opponent(tmp, scene);
        if (!tmp->bullet || tmp->bullet->pos.x <= 0 || tmp->bullet->pos.y <= 0
            || tmp->bullet->pos.x >= 1200 || tmp->bullet->pos.y >= 800)
            create_bullet(scene, tmp, scene->opp);
        tmp = tmp->next;
    }
}
