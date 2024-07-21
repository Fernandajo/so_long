/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:21:19 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/16 17:16:30 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_coords(t_coord *s, t_coord *e, t_coord *c)
{
	t_coord	*tmp;

	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
	while (e)
	{
		tmp = e->next;
		free(e);
		e = tmp;
	}
	while (c)
	{
		tmp = c->next;
		free(c);
		c = tmp;
	}
}

void	free_file(char **file)
{
	int	i;
	int	lines;

	lines = count_lines_file(file);
	i = 0;
	while (i < lines)
	{
		free(file[i]);
		i++;
	}
	free(file);
}

void	free_matrix(char **matrix, int size_y)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	close_connection(t_game *game)
{
	if (game->coletables > 0 && game->win_ptr != NULL)
		ft_printf("You lost D:\n");
	else if (game->coletables == 0 && game->win_ptr != NULL)
		ft_printf("You Won in only %d steps!\nCongratulations!\n", game->steps);
	free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_all(t_game *game)
{
	if (game->s_img)
	{
		if (game->s_img->background != NULL)
			mlx_destroy_image(game->mlx_ptr, game->s_img->background);
		if (game->s_img->wall != NULL)
			mlx_destroy_image(game->mlx_ptr, game->s_img->wall);
		if (game->s_img->exit != NULL)
			mlx_destroy_image(game->mlx_ptr, game->s_img->exit);
		if (game->s_img->collectable != NULL)
			mlx_destroy_image(game->mlx_ptr, game->s_img->collectable);
		if (game->s_img->player != NULL)
			mlx_destroy_image(game->mlx_ptr, game->s_img->player);
	}
	if (game->win_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr != NULL)
		mlx_destroy_display(game->mlx_ptr);
	if (game->matrix)
		free_matrix(game->matrix, game->size_y);
	free(game->s_img);
	free(game->mlx_ptr);
	free(game);
}
