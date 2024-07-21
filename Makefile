# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 14:10:24 by fjoestin          #+#    #+#              #
#    Updated: 2024/04/11 08:50:21 by fjoestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   so_long

CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra -Imlx -g

MLXFLAGS=   -L ./libraries/mlx -lmlx -lXext -lX11

LIBS    =    ./libraries/Libft/libft.a

PRINTF  =    ./libraries/ft_printf/libftprintf.a

GNL     =    ./libraries/gnl/get_next_line.a

SRCS	=	so_long.c maps.c maps_helper.c error.c window.c inputs.c paths.c paths_helper.c updates.c

OBJS	=	$(addprefix output/,$(SRCS:.c=.o))

all:		$(NAME)
$(NAME): $(OBJS)
			make -C ./libraries/mlx
			make -C ./libraries/Libft
			make -C ./libraries/ft_printf
			make -C ./libraries/gnl
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(PRINTF) $(GNL) $(MLXFLAGS) -o $(NAME)

output/%.o: %.c | output
		$(CC) $(CFLAGS) -c $< -o $@
	
output:
		mkdir -p output
	
clean:
			make clean -C ./libraries/mlx
			make clean -C ./libraries/Libft
			make clean -C ./libraries/ft_printf
			make clean -C ./libraries/gnl
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME) $(LIBS) $(PRINTF) $(GNL)
			
re:			fclean all

norminette:
			norminette so_long.c maps.c maps_helper.c error.c window.c inputs.c paths.c paths_helper.c updates.c
.PHONY: all clean fclean re
