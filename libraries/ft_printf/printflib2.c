/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:42 by fjoestin          #+#    #+#             */
/*   Updated: 2024/01/14 21:54:13 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	return (ft_putchar(c));
}

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (ft_putstr("(null)"));
	else
		return (ft_putstr(str));
}

int	print_digit(va_list args)
{
	int	c;

	c = va_arg(args, int);
	return (ft_putnbr((long)c));
}

int	print_hexa(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_puthex((unsigned long long int)nb, 1));
}

int	print_hexaup(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_puthex((unsigned long long int)nb, 2));
}
