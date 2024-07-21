/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:10:12 by fjoestin          #+#    #+#             */
/*   Updated: 2024/01/14 21:20:58 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		print_format(char specifier, va_list args);
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long n);
int		ft_puthex(unsigned long long int n, int boolean);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_digit(va_list args);
int		print_hexa(va_list args);
int		print_hexaup(va_list args);
int		print_ptr(va_list args);
int		print_unsigned(va_list args);

#endif