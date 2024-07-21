# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:32:36 by fjoestin          #+#    #+#              #
#    Updated: 2024/01/14 21:55:59 by fjoestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c printflib.c \
printflib2.c printflib3.c

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re