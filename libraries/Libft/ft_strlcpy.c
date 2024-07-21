/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:52:48 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/05 20:50:55 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize <= 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	while (src[i])
		i++;
	return (i);
}

/* int	main(void)
{
	char dst[10];
	const char* src = "aaa";
	size_t dstsize = 10;

	ft_strlcpy(dst, src, dstsize);
    printf("%s", dst);

    printf("\n");

	strncpy(dst, src, dstsize);
    printf("%s", dst);

    return 0;
} */