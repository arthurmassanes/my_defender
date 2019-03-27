/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** increase/decrease fps
*/

#include "my_defender.h"

int decrease_fps(sfRenderWindow *win, scene_t *scene)
{
    scene->fps = scene->fps > 10 ? scene->fps - 1 : scene->fps;
    sfRenderWindow_setFramerateLimit(win, scene->fps);
    sfText_setString(scene->messages[2], my_getnbr(scene->fps));
    return (scene->fps);
}

int increase_fps(sfRenderWindow *win, scene_t *scene)
{
    scene->fps = scene->fps < 100 ? scene->fps + 1 : scene->fps;
    sfRenderWindow_setFramerateLimit(win, scene->fps);
    sfText_setString(scene->messages[2], my_getnbr(scene->fps));
    return (scene->fps);
}
