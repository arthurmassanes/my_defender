/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** text drawing
*/

#include "my_defender.h"

sfText **create_game_messages(void)
{
    sfText **messages = malloc(sizeof(sfText *) * 6);

    if (!messages)
        return (0);
    messages[0] = create_text("health: ", 35, (sfVector2f){1110, 420});
    messages[1] = create_text("100", 35, (sfVector2f){1220, 420});
    messages[2] = create_text("wave: ", 45, (sfVector2f){1105, -10});
    messages[3] = create_text("1", 40, (sfVector2f){1210, -5});
    messages[4] = create_text("100", 45, (sfVector2f){55, 85});
    messages[5] = 0;
    sfText_setColor(messages[0], sfRed);
    sfText_setColor(messages[1], sfRed);
    sfText_setColor(messages[2], sfBlack);
    sfText_setColor(messages[3], sfBlack);
    sfText_setColor(messages[4], sfYellow);
    return (messages);
}

sfText *create_text(char *text, int size, sfVector2f pos)
{
    sfText *text_obj = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);

    if (!text_obj || !font)
        return (NULL);
    sfText_setFont(text_obj, font);
    sfText_setCharacterSize(text_obj, size);
    sfText_setString(text_obj, text);
    sfText_setPosition(text_obj, pos);
    return (text_obj);
}

void draw_text(sfRenderWindow *win, char *text, sfVector2f pos, int size)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);

    if (!text || !txt || !font || size < 1)
        return;
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, size);
    sfText_setString(txt, text);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(win, txt, 0);
    sfFont_destroy(font);
    sfText_destroy(txt);
}
