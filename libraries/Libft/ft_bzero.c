/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:34:10 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/05 20:40:39 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_s;

	tmp_s = (char *)(s);
	while (0 < n)
	{
		*(tmp_s++) = '\0';
		n--;
	}
}

/* int	main()
{
	char str[10];

	ft_bzero(str, sizeof(char) * 10);
	for(int i = 0; i < 10; i++)
		printf("%c", str[i]);
} */