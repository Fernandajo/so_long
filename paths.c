/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:24:16 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 08:36:49 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*get_all_coords(char **file, char c)
{
	t_coord	*head_coord;
	int		row;
	int		column;

	row = 0;
	column = 0;
	head_coord = NULL;
	while (file[row] != NULL)
	{
		while (file[row][column])
		{
			if (file[row][column] == c)
				head_coord = add_coord_to_list(head_coord, row, column, c);
			column++;
		}
		row++;
		column = 0;
	}
	return (head_coord);
}

t_coord	*add_coord_to_list(t_coord *head_coord, int row, int column, char c)
{
	t_coord	*new_coord;
	t_coord	*head_coord_copy;

	new_coord = malloc(sizeof(t_coord));
	new_coord->character = c;
	new_coord->column = column;
	new_coord->row = row;
	new_coord->next = NULL;
	if (!head_coord)
		return (new_coord);
	head_coord_copy = head_coord;
	while (head_coord->next)
		head_coord = head_coord->next;
	head_coord->next = new_coord;
	return (head_coord_copy);
}

int	check_path_possible(char **f, int row, int column, t_coord *to_coord)
{
	if (check_coords(f, row + 1, column, to_coord))
		return (1);
	if (check_coords(f, row - 1, column, to_coord))
		return (1);
	if (check_coords(f, row, column + 1, to_coord))
		return (1);
	if (check_coords(f, row, column - 1, to_coord))
		return (1);
	return (0);
}

int	check_all_paths_poss(char **f, char **copy, t_coord *from, t_coord *to)
{
	t_coord	*to_head;

	to_head = to;
	while (from)
	{
		while (to)
		{
			if (!check_path_possible(copy, from->row, from->column, to))
				return (free_file(f), free_file(copy), 0);
			to = to->next;
		}
		to = to_head;
		from = from->next;
	}
	return (free_file(f), free_file(copy), 1);
}

int	check_has_valid_paths(t_game *game, char *map)
{
	char	**file;
	char	**copy;
	t_coord	*s_coords;
	t_coord	*e_coords;
	t_coord	*c_coords;

	file = put_map_matrix(game, map);
	copy = put_map_matrix(game, map);
	if (!file)
		return (0);
	s_coords = get_all_coords(file, 'P');
	e_coords = get_all_coords(file, 'E');
	c_coords = get_all_coords(file, 'C');
	if (!check_all_paths_poss(file, copy, s_coords, e_coords))
	{
		free_coords(s_coords, e_coords, c_coords);
		return (0);
	}
	free_coords(s_coords, e_coords, c_coords);
	return (1);
}
