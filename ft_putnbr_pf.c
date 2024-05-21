/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:52:14 by bhocsak           #+#    #+#             */
/*   Updated: 2024/05/06 18:40:01 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		n *= -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr_pf(n / 10);
	}
	ft_putchar_pf(n % 10 + '0');
	return (count);
}
