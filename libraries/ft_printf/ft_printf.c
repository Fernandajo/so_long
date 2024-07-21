/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:58:05 by fjoestin          #+#    #+#             */
/*   Updated: 2024/01/14 22:01:51 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(args);
	else if (specifier == 's')
		count += print_str(args);
	else if (specifier == 'p')
		count += print_ptr(args);
	else if (specifier == 'i' || specifier == 'd')
		count += print_digit(args);
	else if (specifier == 'u')
		count += print_unsigned(args);
	else if (specifier == 'x')
		count += print_hexa(args);
	else if (specifier == 'X')
		count += print_hexaup(args);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += print_format(format[i++], args);
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(args);
	return (count);
}
