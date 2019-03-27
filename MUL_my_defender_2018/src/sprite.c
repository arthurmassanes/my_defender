/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** creating and destroying sprites
*/

#include "my_defender.h"

game_object_t *create_object(char *filepath, sfVector2f pos)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(filepath, 0);
    if (!object->sprite || !object->texture || !object) {
        my_putstr("Error: could not create sprite ");
        my_putstr(filepath);
        my_putstr("\n");
        return (0);
    }
    sfSprite_setTexture(object->sprite, object->texture, 0);
    sfSprite_setPosition(object->sprite, pos);
    object->pos = pos;
    object->next = NULL;
    return (object);
}

void destroy_game_object(game_object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}
