/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:28:00 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/16 17:21:18 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0 = false 1 = true

int	check_txt(char *map)
{
	if (ft_strlen(map) > 4)
	{
		if (ft_strnstr(map, ".ber\0", ft_strlen(map)))
			return (1);
	}
	return (0);
}

int	check_size(t_game *game, char *map)
{
	int		fd;
	int		width;
	int		count_height;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	count_height = 0;
	line = get_next_line(fd);
	width = ft_linelen(line);
	while (line)
	{
		count_height++;
		if (width != ft_linelen(line))
			return (free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	game->size_y = count_height;
	game->size_x = width;
	return (close(fd), free(line), 1);
}

int	check_is_surrounded_by_walls(char *map)
{
	int		fd;
	char	*line;
	char	*last_line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	last_line = NULL;
	line = get_next_line(fd);
	if (!is_wall(line))
		return (free(line), close(fd), 0);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (!(line[0] == '1' && line[ft_linelen(line) - 1] == '1'))
			return (free(line), free(last_line), close(fd), 0);
		if (last_line)
			free(last_line);
		last_line = line;
		line = get_next_line(fd);
	}
	if (!is_wall(last_line))
		return (free(last_line), close(fd), 0);
	return (free(last_line), close(fd), 1);
}

int	check_has_characters(t_game *game, char *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**mapfile;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			if (!ft_strchr("10ECP", line[i++]))
				return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	mapfile = put_map_matrix(game, map);
	if (count(mapfile, 'C') <= 0 || count(mapfile, 'E') != 1
		|| count(mapfile, 'P') != 1)
		return (free_matrix(mapfile, game->size_y), 0);
	return (free_matrix(mapfile, game->size_y), 1);
}

int	map_check(t_game *game, char *map)
{
	if (!check_txt(map))
		return (ft_printf(ERR_FORMAT), 0);
	if (!check_size(game, map))
		return (ft_printf(ERR_NOTRECT), 0);
	if (!check_is_surrounded_by_walls(map))
		return (ft_printf(ERR_WALL), 0);
	if (!check_has_characters(game, map))
		return (ft_printf(ERR_INVCHAR), 0);
	if (!check_has_valid_paths(game, map))
		return (ft_printf(ERR_FLOOD), 0);
	return (1);
}
