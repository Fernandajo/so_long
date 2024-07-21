/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:19:18 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 08:43:17 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	prepare_window(t_game *game, char *map)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (0);
	game->matrix = put_map_matrix(game, map);
	game->coletables = count(game->matrix, COLLEC_SYMB);
	game->steps = 0;
	game->px_per_sq = 64;
	game->width = game->size_x * game->px_per_sq;
	game->height = game->size_y * game->px_per_sq;
	game->win_ptr = mlx_new_window
		(game->mlx_ptr, game->width, game->height, "CASINO NIGHT");
	if (game->win_ptr == NULL)
		return (free(game->win_ptr), 0);
	return (1);
}

t_img	*load_img(t_game *game)
{
	t_img	*image;
	int		width;
	int		height;

	image = ft_calloc(5, sizeof(t_img));
	image->background = mlx_xpm_file_to_image
		(game->mlx_ptr, "./img/darkred.xpm", &width, &height);
	image->exit = mlx_xpm_file_to_image
		(game->mlx_ptr, "./img/bank.xpm", &width, &height);
	image->player = mlx_xpm_file_to_image
		(game->mlx_ptr, "./img/persona.xpm", &width, &height);
	image->collectable = mlx_xpm_file_to_image
		(game->mlx_ptr, "./img/coins.xpm", &width, &height);
	image->wall = mlx_xpm_file_to_image
		(game->mlx_ptr, "./img/casino.xpm", &width, &height);
	if (!image->background || !image->exit 
		|| !image->player || !image->collectable || !image->wall)
		error_image(game);
	return (image);
}

void	put_image(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->s_img->background, 0, 0);
	j = 0;
	map = game->matrix;
	while (map[j])
	{
		i = 0;
		while (i <= game->size_x)
		{
			add_image(map[j][i], i * 64, j * 64, game);
			i++;
		}
		j++;
	}
}

void	add_image(char c, int x, int y, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr, game->s_img->wall, x, y);
	if (c == 'E')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr, game->s_img->exit, x, y);
	if (c == 'C')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr, game->s_img->collectable, x, y);
	if (c == 'P')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr, game->s_img->player, x, y);
}

void	error_image(t_game *game)
{
	ft_printf(ERR_IMAGE);
	close_connection(game);
}
