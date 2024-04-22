/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** mon_rpg.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "mon_rpg.h"

int init_resources(window_t *mon_game, parallax_t *parallax)
{
    sfVideoMode mode = {1920, 1080, 32};
    mon_game->window = sfRenderWindow_create(mode, "My window", sfResize | sfClose, NULL);

    if (!mon_game->window)
        return ERROR;

    init_parallax(parallax);

    return SUCCESS;
}

void delete_resources(window_t *mon_game, parallax_t *parallax)
{
    sfRenderWindow_destroy(mon_game->window);
    // Free parallax
    sfSprite_destroy(parallax->background_sprite);
    sfTexture_destroy(parallax->background_texture);
    free(mon_game);
}
