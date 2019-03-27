/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** wave
*/

#include "my_defender.h"

void spawn_opponents(scene_t *scene)
{
    if (!scene->opp && scene->wave) {
        scene->wave++;
        sfText_setString(scene->messages[3], my_getnbr(scene->wave));
        scene->opp = create_opponents((scene->wave * 5 * 0.5), 100);
    }
}
