/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:12:51 by fjoestin          #+#    #+#             */
/*   Updated: 2024/01/14 21:56:26 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar((int)str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(-n) + 1);
	}
	else if (n < 10)
		return (ft_putchar(n + '0'));
	else
	{
		count = ft_putnbr(n / 10);
		return (count + ft_putnbr(n % 10));
	}
}

int	ft_puthex(unsigned long long int n, int boolean)
{
	int		count;
	char	*symbols;

	if (boolean == 1)
		symbols = "0123456789abcdef";
	else if (boolean == 2)
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_puthex(-n, boolean) + 1);
	}
	else if (n < 16)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_puthex(n / 16, boolean);
		return (count + ft_puthex(n % 16, boolean));
	}
}
