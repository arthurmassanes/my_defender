/*
** EPITECH PROJECT, 2018
** framebuffer_create
** File description:
** function for creating a framebuffer
*/

#include <stdlib.h>
#include "framebuffer.h"

void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    int pos = (x * framebuffer->width * 4) + (y * 4);

    framebuffer->pixels[pos] = color.r;
    framebuffer->pixels[pos + 1] = color.g;
    framebuffer->pixels[pos + 2] = color.b;
    framebuffer->pixels[pos + 3] = color.a;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buffer;

    buffer = malloc(sizeof(framebuffer_t));
    buffer->width = width;
    buffer->height = height;
    buffer->pixels = malloc(width * height * 4);
    return (buffer);
}
