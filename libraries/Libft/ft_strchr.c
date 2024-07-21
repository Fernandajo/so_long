/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:41:01 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/05 21:04:57 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	ch = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			break ;
		i++;
	}
	if (ch == str[i])
		return (&str[i]);
	else
		return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char string[] = {"Hello, world!"};
	printf("%s\n", ft_strchr(string, '\0'));
} */