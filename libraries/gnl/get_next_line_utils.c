/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:41:43 by fjoestin          #+#    #+#             */
/*   Updated: 2024/02/19 15:34:06 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	char	*tmp_s;

	tmp_s = (char *)(s);
	while (0 < n)
	{
		*(tmp_s++) = '\0';
		n--;
	}
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	unsigned char	*tmp;

	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero_gnl(tmp, (size * count));
	return (tmp);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen_gnl(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	size;
	size_t	i;
	char	*ptr;

	length = ft_strlen_gnl(s);
	i = 0;
	size = length - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < len && i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1)
		s1 = ft_calloc_gnl(1, 1);
	i = 0;
	ptr = (char *)malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (free (s1), ptr);
}
