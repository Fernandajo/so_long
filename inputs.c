/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:36:01 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 08:48:53 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_manager(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_connection(game);
	if (keycode == W_KEY || keycode == UP_ARROW_KEY)
		move_up(game);
	if (keycode == S_KEY || keycode == DOWN_ARROW_KEY)
		move_down(game);
	if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
		move_right(game);
	if (keycode == A_KEY || keycode == LEFT_ARROW_KEY)
		move_left(game);
	return (EXIT_SUCCESS);
}

void	move_up(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->matrix[j])
	{
		i = 0;
		while (game->matrix[j][i] != 'P' && game->matrix[j][i] != '\0')
			i++;
		if (game->matrix[j][i] == 'P')
			break ;
		j++;
	}
	if (game->matrix[j - 1][i] == COLLEC_SYMB)
		game->coletables--;
	if (game->matrix[j - 1][i] == EXIT_SYMB && game->coletables == 0)
		dostuff_up(game, j, i);
	if (game->matrix[j - 1][i] != WALL_SYMB
		&& game->matrix[j - 1][i] != EXIT_SYMB)
	{
		update_step(game);
		game->matrix[j][i] = GROUND_SYMB;
		game->matrix[j - 1][i] = PLAYER_SYMB;
		put_image(game);
	}
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->matrix[j])
	{
		i = 0;
		while (game->matrix[j][i] != 'P' && game->matrix[j][i] != '\0')
			i++;
		if (game->matrix[j][i] == 'P')
			break ;
		j++;
	}
	if (game->matrix[j + 1][i] == COLLEC_SYMB)
		game->coletables--;
	if (game->matrix[j + 1][i] == EXIT_SYMB && game->coletables == 0)
		dostuff_down(game, j, i);
	if (game->matrix[j + 1][i] != WALL_SYMB
		&& game->matrix[j + 1][i] != EXIT_SYMB)
	{
		update_step(game);
		game->matrix[j][i] = GROUND_SYMB;
		game->matrix[j + 1][i] = PLAYER_SYMB;
		put_image(game);
	}
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->matrix[j])
	{
		i = 0;
		while (game->matrix[j][i] != 'P' && game->matrix[j][i] != '\0')
			i++;
		if (game->matrix[j][i] == 'P')
			break ;
		j++;
	}
	if (game->matrix[j][i - 1] == COLLEC_SYMB)
		game->coletables--;
	if (game->matrix[j][i - 1] == EXIT_SYMB && game->coletables == 0)
		dostuff_left(game, j, i);
	if (game->matrix[j][i - 1] != WALL_SYMB
		&& game->matrix[j][i - 1] != EXIT_SYMB)
	{
		update_step(game);
		game->matrix[j][i] = GROUND_SYMB;
		game->matrix[j][i - 1] = PLAYER_SYMB;
		put_image(game);
	}
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->matrix[j])
	{
		i = 0;
		while (game->matrix[j][i] != 'P' && game->matrix[j][i] != '\0')
			i++;
		if (game->matrix[j][i] == 'P')
			break ;
		j++;
	}
	if (game->matrix[j][i + 1] == COLLEC_SYMB)
		game->coletables--;
	if (game->matrix[j][i + 1] == EXIT_SYMB && game->coletables == 0)
		dostuff_right(game, j, i);
	if (game->matrix[j][i + 1] != WALL_SYMB
		&& game->matrix[j][i + 1] != EXIT_SYMB)
	{
		update_step(game);
		game->matrix[j][i] = GROUND_SYMB;
		game->matrix[j][i + 1] = PLAYER_SYMB;
		put_image(game);
	}
}
