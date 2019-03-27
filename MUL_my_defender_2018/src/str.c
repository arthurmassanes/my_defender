/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** str functions
*/

#include "my_defender.h"

int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strncmp(char *s1, char *s2, int n)
{
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (-1);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (-1);
    }
    return (0);
}

char *my_revstr(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen(str) + 1);
    int target = 0;

    for (int i = my_strlen(str) - 1; i >= 0; i--, target++)
        dup[target] = str[i];
    dup[my_strlen(str)] = 0;
    return (dup);
}
