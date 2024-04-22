/*
** EPITECH PROJECT, 2024
** workshop-csfml
** File description:
** parallax
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "mon_rpg.h"

void create_parallax_textures(parallax_t *parallax)
{
    // Création des textures
}

void create_parallax(parallax_t *parallax, int i)
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {6, 6};
    // Création du sprite i 
}

void init_parallax(parallax_t *parallax)
{
    parallax->background_texture = sfTexture_createFromFile("assets/parallax/bg_parallax.png", NULL);
    parallax->background_sprite = sfSprite_create();

    sfSprite_setTexture(parallax->background_sprite, parallax->background_texture, sfTrue);
    sfSprite_setPosition(parallax->background_sprite, (sfVector2f){0, 0});
    sfSprite_setScale(parallax->background_sprite, (sfVector2f){6, 6});

    // appel pour Création des textures
    // appel pour Création des sprites
}

void draw_parallax(sfRenderWindow *window, parallax_t *parallax)
{
    sfRenderWindow_drawSprite(window, parallax->background_sprite, NULL);
    // Affichage des parallax
}

void move_parallax(parallax_t *parallax)
{
    // Déplacement des parallax
}
