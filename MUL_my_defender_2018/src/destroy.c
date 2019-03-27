/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** struct destroying functions
*/

#include "my_defender.h"

void destroy_sound(sound_t *sound)
{
    sfSound_destroy(sound->snd);
    sfSoundBuffer_destroy(sound->sb);
}

int exit_pause(sfRenderWindow *win, scene_t *scene)
{
    destroy_scene(scene);
    scene->play = 3;
}

int end_game(sfRenderWindow *win, scene_t *scene)
{
    sfRenderWindow_close(win);
    destroy_scene(scene);
    if (scene->play == 2)
        return (2);
    return (0);
}

void destroy_scene(scene_t *scene)
{
    for (int i = 0; scene->objs[i]; ++i)
        destroy_game_object(scene->objs[i]);
    for (int i = 0; scene->buttons[i]; ++i)
        sfRectangleShape_destroy(scene->buttons[i]->rect);
    for (int i = 0; scene->messages[i]; ++i)
        sfText_destroy(scene->messages[i]);
    destroy_sound(scene->shot);
    if (scene->theme != NULL)
        sfMusic_destroy(scene->theme);
    free(scene);
}
