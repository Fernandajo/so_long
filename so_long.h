/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:55:06 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/11 08:43:31 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libraries/mlx/mlx.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/gnl/get_next_line.h"
# include "libraries/Libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define ERR_HIGHCOUNT	"Error\nMore than 1 start or exit\n"
# define ERR_LESSPOI	"Error\nMap must contain at least 1 P, E, and C\n"
# define ERR_NOTRECT	"Error\nMap must be a rectangle\n"
# define ERR_INVCHAR	"Error\nMap contains invalid characters\n"
# define ERR_WALL		"Error\nWalls must enclose the play area\n"
# define ERR_FLOOD		"Error\nNo valid path to all regions of the play area\n"
# define ERR_FORMAT		"Error\nInvalid map file format\n"
# define ERR_MALLOC		"Error\nMalloc failed to allocate memory\n"
# define ERR_IMAGE		"Error\nImage has failed to be initialted\n"
# define ERR_ARGS		"Error\nProgram takes exactly 2 arguments\n"
# define ERR_NOFILE		"Error\nfile name not found\n"

typedef enum e_map_symb {
	WALL_SYMB = '1',
	GROUND_SYMB = '0',
	EXIT_SYMB = 'E',
	COLLEC_SYMB = 'C',
	PLAYER_SYMB = 'P',
	FLOOD_SYMB = '2',
	PC_SYMB = 'c',
}	t_map_symb;

typedef enum e_key_code {
	CLOSE_ICON = 17,
	ESC_KEY = 65307,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP_ARROW_KEY = 65362,
	DOWN_ARROW_KEY = 65364,
	LEFT_ARROW_KEY = 65361,
	RIGHT_ARROW_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
}	t_key_code;

typedef struct s_coord
{
	int				character;
	int				row;
	int				column;
	struct s_coord	*next;
}	t_coord;

typedef struct s_img {
	void	*background;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*player;
}		t_img;

typedef struct s_game {
	t_img	*s_img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	char	**matrix;
	int		coletables;
	int		width;
	int		height;
	int		px_per_sq;
	int		steps;
}	t_game;

// main + so long
void	so_long(t_game *game, char *map);

// maps
int		map_check(t_game *game, char *map);
int		check_has_characters(t_game *game, char *map);
char	**put_map_matrix(t_game *game, char *map);
int		check_is_surrounded_by_walls(char *map);
int		check_size(t_game *game, char *map);
int		check_txt(char *map);

// maps helper
int		ft_linelen(char *line);
int		is_wall(char *line);
int		count(char **mapfile, char c);
int		count_lines_file(char **file);

// window
int		prepare_window(t_game *game, char *map);
t_img	*load_img(t_game *game);
void	put_image(t_game *game);
void	add_image(char c, int x, int y, t_game *game);

// errors
void	free_matrix(char **matrix, int size_y);
void	free_all(t_game *game);
void	free_coords(t_coord *s, t_coord *e, t_coord *c);
void	free_file(char **file);
void	error_image(t_game *game);
int		close_connection(t_game *game);

// inputs
//int	handle_input(int keysym, t_game *data);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		input_manager(int keycode, t_game *game);
void	update_step(t_game *game);

//updates
char	**find_player(t_game *game);
void	dostuff_up(t_game *game, int h, int w);
void	dostuff_down(t_game *game, int h, int w);
void	dostuff_left(t_game *game, int h, int w);
void	dostuff_right(t_game *game, int h, int w);

// paths
int		check_has_valid_paths(t_game *game, char *map);
t_coord	*get_all_coords(char **file, char c);
t_coord	*add_coord_to_list(t_coord *head_coord, int row, int column, char c);
int		check_all_paths_poss(char **f, char **copy, t_coord *from, t_coord *to);
int		check_path_possible(char **f, int row, int column, t_coord *to_coord);
int		check_coords(char **file, int row, int column, t_coord *to_coord);

#endif
