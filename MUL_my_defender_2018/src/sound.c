/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonction to change sound
*/

#include "my_defender.h"

int sound_low(sfRenderWindow *win, scene_t *scene)
{
    float volume = sfMusic_getVolume(scene->theme);
    sfSoundStatus status = sfMusic_getStatus(scene->theme);

    if (volume > 10) {
        sfMusic_setVolume(scene->theme, volume - 10);
        status != sfStopped ? scene->volume = volume - 10 : 0;
    }
}

int sound_up(sfRenderWindow *win, scene_t *scene)
{
    float volume = sfMusic_getVolume(scene->theme);
    sfSoundStatus status = sfMusic_getStatus(scene->theme);

    if (volume < 90) {
	sfMusic_setVolume(scene->theme, volume + 10);
        status != sfStopped ? scene->volume = volume + 10 : 0;
    }
}

int sound_on(sfRenderWindow *win, scene_t *scene)
{
    sfSoundStatus status = sfMusic_getStatus(scene->theme);

    if (status == sfStopped)
        sfMusic_play(scene->theme);
}

int sound_off(sfRenderWindow *win, scene_t *scene)
{
    sfSoundStatus status = sfMusic_getStatus(scene->theme);

    if (status == sfPlaying) {
	sfMusic_stop(scene->theme);
        scene->volume = 0;
    }
}
