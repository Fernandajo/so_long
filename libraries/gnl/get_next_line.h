/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:31:34 by fjoestin          #+#    #+#             */
/*   Updated: 2024/02/19 15:35:13 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_strlen_gnl(const char *str);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strdup_gnl(const char *s1);
char		*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char		*ft_strjoin_gnl(char *s1, const char *s2);
void		ft_bzero_gnl(void *s, size_t n);
void		*ft_calloc_gnl(size_t count, size_t size);
char		*get_next_line(int fd);
int			check_line(char *str);
char		*_next_line(char *keep, int bytesread);
char		*_fill_line(char *keep, int bytesread);

#endif