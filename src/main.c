/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "mon_rpg.h"

void game_loop(window_t *mon_game, parallax_t *parallax)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(mon_game->window)) {
        while (sfRenderWindow_pollEvent(mon_game->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(mon_game->window);
        }
        mon_game->time = sfClock_getElapsedTime(mon_game->clock);
        mon_game->seconds = mon_game->time.microseconds / 1000000.0;
        if (mon_game->seconds > 0.005) {
            move_parallax(parallax);
            sfClock_restart(mon_game->clock);
        }
        draw_parallax(mon_game->window, parallax);
        sfRenderWindow_display(mon_game->window);
        sfRenderWindow_clear(mon_game->window, sfBlack);
    }
}

int main(int argc, const char* argv[])
{
    (void) argc; (void) argv;

    window_t *mon_game = malloc(sizeof(window_t));
    parallax_t *parallax = malloc(sizeof(parallax_t));

    if (mon_game == NULL)
        return ERROR;

    if (init_resources(mon_game, parallax) == ERROR)
        return ERROR;

    game_loop(mon_game, parallax);

    delete_resources(mon_game, parallax);

    return SUCCESS;
}