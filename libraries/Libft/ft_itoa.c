/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:55:11 by fjoestin          #+#    #+#             */
/*   Updated: 2023/12/06 15:58:32 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n);

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			temp;
	long int	longy;

	longy = n;
	len = int_len(n) - 1;
	str = (char *)malloc((len + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + 1] = '\0';
	if (longy < 0)
	{
		str[0] = '-';
		longy *= -1;
	}
	while (longy > 9)
	{
		temp = longy % 10;
		longy /= 10;
		str[len] = (char)(temp + 48);
		len--;
	}
	str[len] = (char)(longy + '0');
	return (str);
}

static int	int_len(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

/* int	main()
{
    int n = 1234567890;
    char *result = ft_itoa(n);
    printf("%s\n", result);
    free(result);
    return 0;
} */