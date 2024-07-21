/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:39 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/05 21:08:18 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	int		i;

	ch = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == ch)
			break ;
		i--;
	}
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char string[] = {"Hello, world!"};
	printf("%s\n", ft_strrchr(string, 'o'));
} */