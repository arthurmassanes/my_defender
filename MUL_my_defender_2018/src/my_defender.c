/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main game file
*/

#include "my_defender.h"

int poll_event(sfRenderWindow *win)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
            return (0);
        }
    }
    return (0);
}

sfRenderWindow *create_window(int width, int height)
{
    sfVideoMode mode = {width, height, 32};
    char name[] = "my_defender";
    sfRenderWindow *window = sfRenderWindow_create(mode, name, sfClose, 0);

    if (!window)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window, FPS);
    return (window);
}

int main_menu(sfRenderWindow *window)
{
    scene_t *menu = create_menu_scene();

    if (!window || !menu)
        return (EXIT_ERROR);
    while (sfRenderWindow_isOpen(window) && menu->play != 1) {
        sfRenderWindow_clear(window, sfBlue);
        draw_scene(window, menu);
        poll_event(window);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            check_btn_click(window, menu);
        sfRenderWindow_display(window);
    }
    destroy_scene(menu);
    return (my_defender(window, menu->volume));
}

int my_defender(sfRenderWindow *win, int volume)
{
    scene_t *scene = create_main_scene(win, volume);

    if (!win || !sfRenderWindow_isOpen(win) || !scene)
        return (end_game(win, scene));
    while (sfRenderWindow_isOpen(win) && scene->play == 0
            && scene->castle_hp > 0) {
        draw_game_scene(win, scene);
        animate_objects(win, scene);
        update_castle_health(scene);
        sfRenderWindow_display(win);
        spawn_opponents(scene);
        fire_bullets(win, scene);
        poll_event(win);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            check_btn_click(win, scene);
    }
    if (scene->castle_hp <= 0)
        return (game_over(win, scene));
    else
        return (end_game(win, scene));
}
