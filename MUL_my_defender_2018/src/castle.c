/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** castle functions (updating its health, etc)
*/

#include "my_defender.h"

void update_castle_health(scene_t *scene)
{
    char *health;
    opponent_t *tmp = scene->opp;

    for (int i = 0; tmp != NULL; i++) {
        if (tmp->pos.x > 1260) {
            scene->castle_hp -= 20;
            opp_destroy(scene, i);
        }
        tmp = tmp->next;
    }
    if (scene->castle_hp == 0)
        sfText_setString(scene->messages[1], "0");
    else
        sfText_setString(scene->messages[1], my_getnbr(scene->castle_hp));
}
