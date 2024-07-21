/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:16:29 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/05 20:45:06 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest_pt;
	const char	*src_pt;

	dest_pt = (char *)dest;
	src_pt = (const char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n)
	{
		dest_pt[i] = src_pt[i];
		i++;
		n--;
	}
	return (dest);
}
