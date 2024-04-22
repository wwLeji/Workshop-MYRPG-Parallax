/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** mon_rpg.h
*/

#ifndef WORKSHOP_CSFML_MON_RPG_H
#define WORKSHOP_CSFML_MON_RPG_H

#define SUCCESS 0
#define ERROR 1
#define EPITECH_ERROR 84

#define NB_PARALLAX 9

typedef struct window_s {
    sfRenderWindow *window;
} window_t;

typedef struct parallax_s {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfSprite *sprites[NB_PARALLAX];
    sfTexture *textures[NB_PARALLAX];
} parallax_t;

int init_resources(window_t *mon_game, parallax_t *parallax);
void delete_resources(window_t *mon_game, parallax_t *parallax);

void draw_parallax(sfRenderWindow *window, parallax_t *parallax);
void move_parallax(parallax_t *parallax);
void init_parallax(parallax_t *parallax);

#endif // WORKSHOP_CSFML_MON_RPG_H
