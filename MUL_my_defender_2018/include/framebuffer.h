/*
** EPITECH PROJECT, 2018
** framebuffer struct
** File description:
** a
*/

#ifndef FRAMEBUFFER_
#define FRAMEBUFFER_

#include <SFML/Config.h>
#include "my_defender.h"

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

typedef struct particule_s {
    sfSprite *sprite;
    struct particule_s *next;
} particule_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
particule_t *put_particle(sfVector2f, sfColor, int, int);

#endif
