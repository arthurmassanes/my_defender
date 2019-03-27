/*
** EPITECH PROJECT, 2019
**  my_defender
** File description:
** short file description
*/

#include "my_defender.h"

int variable_display_is_set(char **ae)
{
    for (int i = 0; ae[i]; i++) {
        if (my_strncmp(ae[i], "DISPLAY=", 8) == 0)
            return (1);
    }
    return (0);
}

int main(int ac, char **av, char **ae)
{
    int ret = 2;

    if (!ae || !ae[0] || !variable_display_is_set(ae))
        return (EXIT_ERROR);
    while (ret == 2)
        ret = main_menu(create_window(WINDOW_WIDTH, WINDOW_HEIGHT));
    return (ret);
}
