/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:16 by fjoestin          #+#    #+#             */
/*   Updated: 2023/11/22 11:52:24 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp_str;

	tmp_str = (unsigned char *)(str);
	while (0 < n)
	{
		*(tmp_str++) = (unsigned char)(c);
		n--;
	}
	return (str);
}

/* int main()
{
	char	buffer[10];

	ft_memset(buffer, 'a', sizeof(char) * 10);
	
	for (int i = 0; i < 10; i++)
		printf("%c", buffer[i]);
	
	
} */