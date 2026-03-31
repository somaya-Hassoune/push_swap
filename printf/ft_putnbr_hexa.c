/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:10:07 by shassoun          #+#    #+#             */
/*   Updated: 2023/12/08 21:38:54 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long nb, char c, int *i)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putnbr_base((nb / 16), c, i);
		ft_putchar(base[nb % 16]);
		(*i)++;
	}
	else if (nb < 16)
	{
		ft_putchar(base[nb % 16]);
		(*i)++;
	}
}

int	ft_putnbr_hexa(unsigned long nb, char c)
{
	int	i;

	i = 0;
	ft_putnbr_base(nb, c, &i);
	return (i);
}
