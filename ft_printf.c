/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:46:11 by bhocsak           #+#    #+#             */
/*   Updated: 2024/05/30 17:53:36 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *specifier, va_list ap)
{
	int	count;

	count = 0;
	if (*specifier == 'c')
		count += ft_putchar_pf(va_arg(ap, int));
	else if (*specifier == 's')
		count += ft_putstr_pf(va_arg(ap, char *));
	else if (*specifier == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (*specifier == 'd' || *specifier == 'i')
		count += ft_putnbr_pf((long)va_arg(ap, int));
	else if (*specifier == 'u')
		count += ft_putuint(va_arg(ap, unsigned int));
	else if (*specifier == 'x' || *specifier == 'X')
	{
		if (*specifier == 'x')
			count += ft_puthex((long)va_arg(ap, unsigned long), 'x');
		else
			count += ft_puthex((long)va_arg(ap, unsigned long), 'X');
	}
	else
		count += write(1, specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_format((char *)format, ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>

int	main()
{
	int	count = 0;
	int og_count = 0;
//	long hex = 454147483649;

	count += ft_printf("\n");
	ft_printf("Myprintf: %i\n", count);
	og_count += printf("\n");
	printf("Ogprintf: %i\n", og_count);
}*/
