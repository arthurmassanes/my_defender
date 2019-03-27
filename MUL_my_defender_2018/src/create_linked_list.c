/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonctions to create game_objects linked lists
*/

#include "my_defender.h"

opponent_t *create_struct(opponent_t *obj, int i, int life)
{
    opponent_t *tmp = malloc(sizeof(opponent_t));

    tmp->pos.x = START_X;
    tmp->pos.y = START_Y;
    tmp->pos.y = tmp->pos.y + (i * OPP_HEIGHT) / 2;
    if (i % 2 == 1)
        tmp->pos.x = tmp->pos.x + OPP_WIDTH + 20;
    tmp->speed.x = 0;
    tmp->speed.y = -3;
    tmp->life = life;
    tmp->next = obj;
    return (tmp);
}

opponent_t *create_opponents(int nb_opp, int life)
{
    opponent_t *obj = NULL;
    opponent_t *tmp;

    for (int i = 0; i < nb_opp; i++)
        obj = create_struct(obj, i, life);
    tmp = obj;
    while (tmp->next != NULL) {
        tmp->next->previous = tmp;
        tmp = tmp->next;
    }
    obj->previous = NULL;
    return (obj);
}

tower_t *add_tower(tower_t *tower, tower_type_t *type, sfVector2f pos)
{
    tower_t *new = malloc(sizeof(tower_t));

    new->bullet = malloc(sizeof(bullet_t));
    if (!new || !type || !new->bullet)
        return (NULL);
    new->bullet = 0;
    new->type = *type;
    new->damage = *type == mage ? 10 : 0;
    new->range = *type == mage ? 200 : 0;
    new->damage = *type == archer ? 20 : new->damage;
    new->range = *type == archer ? 300 : new->range;
    new->damage = *type == freeze ? 1 : new->damage;
    new->range = *type == freeze ? 220 : new->range;
    new->damage = *type == cancrelat ? 25 : new->damage;
    new->range = *type == cancrelat ? 1000 : new->range;
    new->pos = pos;
    new->wid = TOWER_WIDTH;
    new->hei = TOWER_WIDTH;
    new->next = tower;
    return (new);
}

game_object_t *create_one_opp(void)
{
    game_object_t *opp = create_object(OPPONENT, START_POS);
    sfIntRect rect = {0, 0, OPP_WIDTH, OPP_HEIGHT};

    sfSprite_setTextureRect(opp->sprite, rect);
    return (opp);
}
