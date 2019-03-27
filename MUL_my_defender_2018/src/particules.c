/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonctions to put a particules effect
*/

#include "framebuffer.h"
#include "my_defender.h"

particule_t *put_particle(sfVector2f pos, sfColor color, int width, int height)
{
    framebuffer_t *fb = framebuffer_create(width, height);
    sfTexture *texture = sfTexture_create(width, height);
    particule_t *particule = malloc(sizeof(particule_t));
    int x = 0;
    int y = 0;

    if (!fb || !texture || !particule)
        return (NULL);
    for (int i = 0; i < width * height / 10; i++) {
        x = rand() % width;
        y = rand() % height;
        my_put_pixel(fb, x, y, color);
    }
    sfTexture_updateFromPixels(texture, fb->pixels, width, height, 0, 0);
    particule->sprite = sfSprite_create();
    sfSprite_setTexture(particule->sprite, texture, sfTrue);
    sfSprite_setPosition(particule->sprite, pos);
    particule->next = NULL;
    return (particule);
}
