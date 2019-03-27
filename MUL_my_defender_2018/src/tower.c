/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonction to put the towers
*/

#include "my_defender.h"

int prepare_archer(sfRenderWindow *win, scene_t *scene)
{
    scene->cur_type = malloc(sizeof(tower_type_t));
    *scene->cur_type = archer;
}

int prepare_mage(sfRenderWindow *win, scene_t *scene)
{
    scene->cur_type = malloc(sizeof(tower_type_t));
    *scene->cur_type = mage;
}

int prepare_freeze(sfRenderWindow *win, scene_t *scene)
{
    scene->cur_type = malloc(sizeof(tower_type_t));
    *scene->cur_type = freeze;
}

int prepare_cancrelat(sfRenderWindow *win, scene_t *scene)
{
    scene->cur_type = malloc(sizeof(tower_type_t));
    *scene->cur_type = cancrelat;
}

int is_tower_valid(sfVector2f posf, scene_t *scene)
{
    if (*scene->cur_type == mage && scene->money >= COST_MAGE) {
        scene->money -= COST_MAGE;
        return (1);
    } else if (*scene->cur_type == archer && scene->money >= COST_ARCH) {
        scene->money -= COST_ARCH;
        return (1);
    }
    scene = scene;
    if (*scene->cur_type == freeze && scene->money >= COST_FREZ) {
        scene->money -= COST_FREZ;
        return (1);
    } else if (*scene->cur_type == cancrelat && scene->money >= COST_CANC) {
        scene->money -= COST_CANC;
        return (1);
    }
    return (0);
}
