/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonction linked to opponents management
*/

#include "my_defender.h"

int first_destroyed(opponent_t *opp)
{
    if (opp == NULL)
        return (1);
    else if (opp->previous == NULL)
        return (1);
    else
        return (0);
}

opponent_t *opp_destroy(scene_t *scene, int i)
{
    opponent_t *opp = scene->opp;

    if (i == 0) {
        scene->opp = scene->opp->next;
        return (NULL);
    }
    for (int j = 0; j < i; j++)
        opp = opp->next;
    if (opp == NULL)
        return (NULL);
    else if (opp->next != NULL && opp->previous != NULL) {
        opp->next->previous = opp->previous;
        opp->previous->next = opp->next;
    }
    opp = opp;
    if (opp->next && !opp->previous)
        opp->next->previous = NULL;
    else if (opp->previous && !opp->next)
        opp->previous->next = NULL;
}

int move_opponents(opponent_t *opp, scene_t *scene)
{
    float tmp = 0;

    for (int i = 0; opp != NULL; i++) {
        if (opp->pos.y <= TURN_HEIGHT && opp->speed.x == 0) {
            tmp = -opp->speed.y;
            opp->speed.y = opp->speed.x;
            opp->speed.x = tmp;
        }
        opp->pos.x += opp->speed.x;
        opp->pos.y += opp->speed.y;
        if (opp->life <= 0) {
            scene->money += 25;
            opp_destroy(scene, i);
        }
        opp = opp->next;
    }
}
