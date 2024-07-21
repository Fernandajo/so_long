/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:48:40 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/05 20:46:40 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*sorc;
	size_t		i;

	dst = dest;
	sorc = src;
	i = -1;
	if (dst == sorc)
		return (dst);
	if (dst < sorc)
	{
		while (++i < n)
			dst[i] = sorc[i];
	}
	else
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = sorc[i - 1];
			i--;
		}
	}
	return (dst);
}
