/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 04:52:39 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/16 17:08:37 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_step(t_game *game)
{
	game->steps++;
	ft_printf("steps: %d\n", game->steps);
}

void	dostuff_up(t_game *game, int h, int w)
{
	update_step(game);
	game->matrix[h][w] = GROUND_SYMB;
	game->matrix[h - 1][w] = PLAYER_SYMB;
	close_connection(game);
}

void	dostuff_down(t_game *game, int h, int w)
{
	update_step(game);
	game->matrix[h][w] = GROUND_SYMB;
	game->matrix[h + 1][w] = PLAYER_SYMB;
	close_connection(game);
}

void	dostuff_left(t_game *game, int h, int w)
{
	update_step(game);
	game->matrix[h][w] = GROUND_SYMB;
	game->matrix[h][w - 1] = PLAYER_SYMB;
	close_connection(game);
}

void	dostuff_right(t_game *game, int h, int w)
{
	update_step(game);
	game->matrix[h][w] = GROUND_SYMB;
	game->matrix[h][w + 1] = PLAYER_SYMB;
	close_connection(game);
}
