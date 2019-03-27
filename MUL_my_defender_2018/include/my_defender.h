/*
** EPITECH PROJECT, 2019
**  my_defender
** File description:
** short file description
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Window.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System/Clock.h>
#include "framebuffer.h"

#define FPS 24
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800
#define GAME "my defender"
#define OPPONENT "img/opponent.png"
#define OPP_WIDTH 50
#define OPP_HEIGHT 70
#define TOWER_WIDTH 70
#define TOWER_HEIGHT 90
#define COST_ARCH 150
#define COST_MAGE 100
#define COST_FREZ 50
#define COST_CANC 2500
#define TURN_HEIGHT 305
#define EXIT_ERROR 84
#define START_X 230
#define START_Y 920
#define START_POS (sfVector2f){230, 920}
#define FONT "fonts/cloisterblack_font.ttf"
#define MENU_IMG "img/menu.png"
#define CREDS "by Maxence Desrousseaux\nmaxence.desrousseaux@epitech.eu\n\n\
& Arthur Massanes\narthur.massanes@epitech.eu\n\nCopyright 2019"
#define OPTIONS "img/options_screen.png"
#define THEME "audio/Oniku_Loop.ogg"
#define GAME_MUS "audio/theme.ogg"
#define BATTLEFIELD "img/battlefield.png"
#define COIN "img/coin.png"
#define ARCHER_TOWER "img/archer_tower.png"
#define MAGE_TOWER "img/mage_tower.png"
#define OPPONENT_INDEX 7
#define FREEZE_TOWER "img/freeze_tower.png"
#define CLICK "audio/click.ogg"
#define FIRE_TOWER "img/fire_tower.png"
#define BULLET "img/bullet.png"
#define GAME_OVER "img/game_over_screen.png"
#define PAUSE_MENU "img/pause_screen.png"
#define LAST_MSG "You made it to wave: "

typedef struct sound_s {
    sfSound *snd;
    sfSoundBuffer *sb;
} sound_t;

struct scene_s;
typedef struct scene_s scene_t;

struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f speed;
    struct game_object_s *next;
    struct game_object_s *previous;
};

typedef struct game_object_s game_object_t;

struct button_s {
    sfRectangleShape *rect;
    char *text;
    int size;
    int (*callback)(sfRenderWindow *, scene_t *);
};

typedef struct button_s button_t;

typedef struct opponent_s {
    int life;
    sfVector2f speed;
    sfVector2f pos;
    struct opponent_s *next;
    struct opponent_s *previous;
} opponent_t;

typedef enum tower_type {
    archer,
    mage,
    freeze,
    cancrelat,
} tower_type_t;

typedef struct bullet_s bullet_t;

typedef struct tower_s {
    enum tower_type type;
    int damage;
    int cost;
    float range;
    float wid;
    float hei;
    sfVector2f pos;
    bullet_t *bullet;
    struct tower_s *next;
    struct tower_s *previous;
} tower_t;

typedef struct particule_s particule_t;

struct scene_s {
    opponent_t *opp;
    tower_t *tower;
    particule_t *particules;
    button_t **buttons;
    game_object_t **objs;
    sfText **messages;
    sfMusic *theme;
    int play;
    int fps;
    int volume;
    sfClock *clock;
    int castle_hp;
    int wave;
    int money;
    tower_type_t *cur_type;
    sound_t *shot;
};

typedef struct scene_s scene_t;

typedef struct bullet_s {
    sfVector2f speed;
    sfVector2f pos;
    enum tower_type type;
} bullet_t;

//    STRING FUNCTIONS
void my_putstr(char *);
int my_strlen(char *);
int my_strncmp(char *, char *, int n);
char *my_getnbr(int nb);
char *my_revstr(char *str);

//   OBJECTS
game_object_t *create_object(char *filepath, sfVector2f pos);

//  ---BUTTONS---
void init_button(button_t *btn, char *txt, sfVector2f pos, sfVector2f size);
int button_is_clicked(button_t button, sfVector2i click_position);
void display_button(sfRenderWindow *, button_t);
int check_btn_click(sfRenderWindow *win, scene_t *scene);
button_t **create_game_buttons(button_t **);
button_t **create_menu_buttons(void);
void create_menu_buttons_callback(button_t **buttons);

// ---TEXT---
sfText *create_text(char *text, int size, sfVector2f pos);
void draw_text(sfRenderWindow *win, char *text, sfVector2f pos, int size);
sfText **create_game_messages(void);

// ------OPPONENT---
void spawn_opponents(scene_t *);
opponent_t *opp_destroy(scene_t *, int);
int first_destroyed(opponent_t *opp);
opponent_t *create_opponents(int nb_opp, int);
game_object_t *create_one_opp(void);
int destroy_opponent(game_object_t *opp);
void draw_opponent_list(sfRenderWindow *, scene_t *);

// ---DESTROY---
int end_game(sfRenderWindow *win, scene_t *scene);
void destroy_game_object(game_object_t *);
void destroy_scene(scene_t *);

int main_menu(sfRenderWindow *);
int my_defender(sfRenderWindow *win, int volume);
scene_t *create_menu_scene(void);
void draw_scene(sfRenderWindow *, scene_t *scene);
scene_t *create_menu_scene(void);
int back_to_menu(sfRenderWindow *, scene_t *);
int option(sfRenderWindow *win, scene_t *scene);
int sound_off(sfRenderWindow *win, scene_t *scene);
int sound_on(sfRenderWindow *win, scene_t *scene);
int sound_up(sfRenderWindow *win, scene_t *scene);
int sound_low(sfRenderWindow *win, scene_t *scene);
int increase_fps(sfRenderWindow *win, scene_t *scene);
int decrease_fps(sfRenderWindow *win, scene_t *scene);
int play(sfRenderWindow *win, scene_t *scene);
int credits(sfRenderWindow *win, scene_t *scene);
int exit_game(sfRenderWindow *win, scene_t *scene);
int pause_game(sfRenderWindow *win, scene_t *scene);
int exit_pause(sfRenderWindow *win, scene_t *scene);
void draw_game_scene(sfRenderWindow *win, scene_t *scene);
void update_castle_health(scene_t *scene);
sfMusic *start_music(char *filepath);
scene_t *create_main_scene(sfRenderWindow *win, int volume);

//    TOWERS
tower_t *add_tower(tower_t *tower, tower_type_t *type, sfVector2f pos);
int prepare_archer(sfRenderWindow *win, scene_t *scene);
int prepare_freeze(sfRenderWindow *win, scene_t *scene);
int prepare_mage(sfRenderWindow *win, scene_t *scene);
int prepare_cancrelat(sfRenderWindow *win, scene_t *scene);
int is_tower_valid(sfVector2f posf, scene_t *scene);
void draw_tower_list(sfRenderWindow *, scene_t *);

//     ANIMATIONS
void animate_objects(sfRenderWindow *, scene_t *scene);
int move_opponents(opponent_t *opp, scene_t *scene);
int anime_opponents(scene_t *);

// --SOUND--
sound_t **create_main_scene_sounds(int volume);
sound_t *create_sound(char *filepath, int volume);

int my_pow(int, int);
int poll_event(sfRenderWindow *win);
sfRenderWindow *create_window(int width, int height);
void fire_bullets(sfRenderWindow *, scene_t *);
void kill_opponent(tower_t *, scene_t *);
void display_bullets(sfRenderWindow *win, scene_t *scene);
int game_over(sfRenderWindow *, scene_t *);
void init_main_scene(scene_t *);

#endif
