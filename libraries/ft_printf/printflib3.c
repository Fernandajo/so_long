/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:53:09 by fjoestin          #+#    #+#             */
/*   Updated: 2024/01/14 21:56:44 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(va_list args)
{
	int						count;
	unsigned long long int	ptr;

	count = 0;
	ptr = va_arg(args, unsigned long long int);
	if (ptr == 0)
	{
		count += ft_putstr("(nil)");
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex(ptr, 1);
	}
	return (count);
}

int	print_unsigned(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr((long)nb));
}
