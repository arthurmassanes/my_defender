/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** creating sounds
*/

#include "my_defender.h"

sound_t **create_main_scene_sounds(int volume)
{
    sound_t **sound = malloc(sizeof(sound_t) * 2);

    if (!sound)
        return (0);
    sound[0] = create_sound(CLICK, volume);
    if (!sound[0])
        return (0);
    sound[1] = 0;
    sfSound_play(sound[1]->snd);
    return (sound);
}

sound_t *create_sound(char *filepath, int volume)
{
    sound_t *sound = malloc(sizeof(sound_t));

    if (!sound)
        return (0);
    sound->sb = sfSoundBuffer_createFromFile(filepath);
    sound->snd = sfSound_create();
    if (!sound->snd || !sound->sb)
        return (0);
    sfSound_setBuffer(sound->snd, sound->sb);
    sfSound_setVolume(sound->snd, volume);
    return (sound);
}
