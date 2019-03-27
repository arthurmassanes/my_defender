/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** number functions
*/

#include "my_defender.h"

int my_pow(int nb, int pow)
{
    int nombre = nb;

    if (pow == 0)
        return (1);
    else if ((nb == 0 || pow < 0) || pow == 0)
        return (0);
    for (int i = 1; i != pow; ++i)
        nb *= nombre;
    return (nb);
}

int nb_len(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *my_getnbr(int nb)
{
    char *str = malloc(sizeof(char) * nb_len(nb) + 1);
    int i = 0;
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        i++;
    }
    if (neg == 1) {
        str[i] = '-';
        i++;
    }
    str[i] = 0;
    str = my_revstr(str);
    return (str);
}
