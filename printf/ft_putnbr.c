/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:51:48 by shassoun          #+#    #+#             */
/*   Updated: 2023/12/08 21:35:00 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_integer(long n, int *i)
{
	if (n < 0)
	{
		ft_putchar('-');
		(*i)++;
		n = -n;
		ft_print_integer(n, i);
	}
	else if (n > 9)
	{
		ft_print_integer((n / 10), i);
		ft_putchar(((n % 10) + 48));
		(*i)++;
	}
	else
	{
		ft_putchar(((n % 10) + 48));
		(*i)++;
	}
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	ft_print_integer(n, &i);
	return (i);
}
