/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:38:08 by fjoestin          #+#    #+#             */
/*   Updated: 2024/02/19 15:35:53 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_line(char *str);
char	*_next_line(char *keep, int bytesread);
char	*_fill_line(char *keep, int bytesread);

char	*get_next_line(int fd)
{
	static char	*keep[1024];
	char		*buffer;
	char		*line;
	int			bytesread;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytesread = 1;
	while (check_line(keep[fd]) == 0)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), 1);
		if (!buffer)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free (buffer);
			break ;
		}
		keep[fd] = ft_strjoin(keep[fd], buffer);
		free (buffer);
	}
	line = _fill_line(keep[fd], bytesread);
	keep[fd] = _next_line(keep[fd], bytesread);
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
	s1 = ft_substr(keep, 0, i);
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
	line = ft_substr(keep, i, (ft_strlen(keep) - i));
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
