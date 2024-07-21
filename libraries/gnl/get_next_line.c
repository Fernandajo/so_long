/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:38:08 by fjoestin          #+#    #+#             */
/*   Updated: 2024/02/19 16:20:06 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_line(char *str);
char	*_next_line(char *keep, int bytesread);
char	*_fill_line(char *keep, int bytesread);

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*buffer;
	char		*line;
	int			bytesread;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytesread = 1;
	while (check_line(keep) == 0)
	{
		buffer = ft_calloc_gnl((BUFFER_SIZE + 1), 1);
		if (!buffer)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free (buffer);
			break ;
		}
		keep = ft_strjoin_gnl(keep, buffer);
		free (buffer);
	}
	line = _fill_line(keep, bytesread);
	keep = _next_line(keep, bytesread);
	return (line);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*_fill_line(char *keep, int bytesread)
{
	int		i;
	char	*s1;

	if (bytesread < 0 || !keep)
		return (NULL);
	i = 0;
	while (keep[i] != '\n' && keep[i] != '\0')
	{
		i++;
	}
	if (keep[i] == '\n')
	{
		i++;
	}
	s1 = ft_substr_gnl(keep, 0, i);
	if (!s1)
		return (NULL);
	return (s1);
}

char	*_next_line(char *keep, int bytesread)
{
	char	*line;
	int		i;

	if (bytesread < 0)
		return (free(keep), NULL);
	if (!keep)
		return (NULL);
	i = 0;
	while (keep[i] != '\n' && keep[i])
	{
		i++;
	}
	if (keep[i] == '\n')
		i++;
	if (!keep[i])
		return (free(keep), NULL);
	line = ft_substr_gnl(keep, i, (ft_strlen_gnl(keep) - i));
	if (!line)
		return (NULL);
	return (free(keep), line);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
