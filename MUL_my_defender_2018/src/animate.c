/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** functions for animating sprites
*/

#include "my_defender.h"

void move_rect(sfSprite *sprite, int offset, int max_width)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    if (rect.left >= max_width - offset)
        rect.left = 0;
    else
        rect.left = rect.left + offset;
    sfSprite_setTextureRect(sprite, rect);
}

int anime_opponents(scene_t *scene)
{
    sfTime anime_time = sfClock_getElapsedTime(scene->clock);
    opponent_t *opp = scene->opp;
    sfIntRect rect;

    while (sfTime_asSeconds(anime_time) < 0.05)
        anime_time = sfClock_getElapsedTime(scene->clock);
    rect = sfSprite_getTextureRect(scene->objs[OPPONENT_INDEX]->sprite);
    if (rect.left >= 200 - OPP_WIDTH) {
        rect.left = 0;
    } else
        rect.left = rect.left + OPP_WIDTH;
    sfSprite_setTextureRect(scene->objs[OPPONENT_INDEX]->sprite, rect);
    move_opponents(opp, scene);
    sfClock_restart(scene->clock);
    return (0);
}

void animate_objects(sfRenderWindow *win, scene_t *scene)
{
    anime_opponents(scene);
    move_rect(scene->objs[1]->sprite, 32, 256);
    for (int i = 2; i < 6; ++i)
        move_rect(scene->objs[i]->sprite, 70, 350);
}
