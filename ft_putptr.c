/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:24:51 by bhocsak           #+#    #+#             */
/*   Updated: 2024/05/07 10:49:02 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	printed;

	printed = 0;
	if (!ptr)
		printed = write(1, "(nil)", 5);
	else
	{
		printed += write(1, "0x", 2);
		printed += ft_puthex((unsigned long)ptr, 'x');
	}
	return (printed);
}
