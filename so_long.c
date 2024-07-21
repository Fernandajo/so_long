/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:53:41 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 10:31:53 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game, char *map)
{
	prepare_window(game, map);
	game->s_img = load_img(game);
	put_image(game);
	mlx_hook(game->win_ptr, CLOSE_ICON, 0, &close_connection, game);
	mlx_hook(game->win_ptr, KEY_PRESS, 1L << 0, &input_manager, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf(ERR_ARGS);
		return (0);
	}
	game = ft_calloc(11, sizeof(t_game));
	if (!game)
	{
		ft_printf(ERR_MALLOC);
		return (free_all(game), 0);
	}
	if (!map_check(game, argv[1]))
		return (free_all(game), 0);
	so_long(game, argv[1]);
	return (0);
}
