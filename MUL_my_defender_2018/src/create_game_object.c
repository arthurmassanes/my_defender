/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** creating game_object_t
*/

#include "my_defender.h"

game_object_t **create_main_scene_objects(void)
{
    game_object_t **objs = malloc(sizeof(game_object_t *) * 9);
    sfIntRect rect = {0, 0, 32, 32};
    sfIntRect tower_rect = {0, 0, 70, 90};

    if (!objs)
        return (0);
    objs[0] = create_object(BATTLEFIELD, (sfVector2f){0, 0});
    objs[1] = create_object(COIN, (sfVector2f){20, 100});
    objs[2] = create_object(ARCHER_TOWER, (sfVector2f){-100, -100});
    objs[3] = create_object(MAGE_TOWER, (sfVector2f){-100, -100});
    objs[4] = create_object(FREEZE_TOWER, (sfVector2f){-100, -100});
    objs[5] = create_object(FIRE_TOWER, (sfVector2f){-100, -100});
    objs[6] = create_object(BULLET, (sfVector2f){-100, -100});
    objs[7] = create_one_opp();
    objs[8] = 0;
    sfSprite_setTextureRect(objs[1]->sprite, rect);
    for (int i = 2; i < 6; ++i)
        sfSprite_setTextureRect(objs[i]->sprite, tower_rect);
    sfSprite_setTextureRect(objs[6]->sprite, (sfIntRect){0, 0, 15, 15});
    return (objs);
}

void init_main_scene(scene_t *scene)
{
    scene->wave = 1;
    scene->money = 100;
    scene->cur_type = NULL;
    scene->tower = NULL;
    scene->play = 0;
}

scene_t *create_main_scene(sfRenderWindow *win, int volume)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return (0);
    scene->clock = sfClock_create();
    scene->objs = create_main_scene_objects();
    scene->buttons = malloc(sizeof(button_t *) * 6);
    scene->messages = create_game_messages();
    scene->shot = create_sound("audio/shoot.ogg", 100);
    if (!scene->objs || !scene->buttons || !scene->messages || !scene->shot)
        return (0);
    scene->buttons = create_game_buttons(scene->buttons);
    scene->opp = create_opponents(3, 100);
    scene->castle_hp = 100;
    scene->theme = start_music(GAME_MUS);
    sfMusic_setVolume(scene->theme, volume);
    init_main_scene(scene);
    return (scene);
}
