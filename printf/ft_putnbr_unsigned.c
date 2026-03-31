/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:29:19 by shassoun          #+#    #+#             */
/*   Updated: 2023/12/08 21:34:52 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_unsigned(unsigned int nb, int *i)
{
	if (nb > 9)
	{
		ft_print_unsigned((nb / 10), i);
		ft_putchar((nb % 10) + 48);
		(*i)++;
	}
	else if (nb <= 9)
	{
		ft_putchar((nb % 10) + 48);
		(*i)++;
	}
}

int	ft_putnbr_unsigned(int nb)
{
	int	i;

	i = 0;
	ft_print_unsigned(nb, &i);
	return (i);
}
