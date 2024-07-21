/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:17 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 07:07:01 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linelen(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	is_wall(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while ((line[i] == '1' || line[i] == '\n') && line[i])
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	count(char **mapfile, char c)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (mapfile[j])
	{
		i = 0;
		while (mapfile[j][i])
		{
			if (mapfile[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

char	**put_map_matrix(t_game *game, char *map)
{
	int		fd;
	int		i;
	char	**matrix;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	matrix = ft_calloc((game->size_y) + 1, sizeof(char *));
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		matrix[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (free(line), matrix);
}

int	count_lines_file(char **file)
{
	int	lines;
	int	i;

	i = 0;
	lines = 0;
	while (file[i])
	{
		lines++;
		i++;
	}
	return (lines);
}
