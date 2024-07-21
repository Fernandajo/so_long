/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:14:37 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 08:33:45 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coords(char **file, int row, int column, t_coord *to_coord)
{
	if (row == to_coord->row && column == to_coord->column)
		return (1);
	else if (file[row][column] == '0' || file[row][column] == 'C')
	{
		file[row][column] = 'X';
		return (check_path_possible(file, row, column, to_coord));
	}
	else
		file[row][column] = 'X';
	return (0);
}
