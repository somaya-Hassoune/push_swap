/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:39:55 by shassoun          #+#    #+#             */
/*   Updated: 2023/12/08 21:34:44 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fct(char c, va_list args)
{
	int	m;

	m = 0;
	if (c == 's')
		m = m + ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		m = m + ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		m = m + ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		m = m + ft_putnbr_hexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		m = m + ft_putnbr_hexa(va_arg(args, unsigned int), 'X');
	else if (c == 'u')
		m = m + ft_putnbr_unsigned(va_arg(args, unsigned long));
	else if (c == 'p')
	{
		m = m + ft_putstr("0x");
		m = m + ft_putnbr_hexa(va_arg(args, unsigned long), 'x');
	}
	else if (c == '%')
		m = m + ft_putchar('%');
	else
		m = m + ft_putchar(c);
	return (m);
}

int	ft_printf(char *s, ...)
{
	char	*current;
	int		m;
	va_list	args;
	int		i;

	va_start(args, s);
	current = s;
	i = 0;
	m = 0;
	while (current[i])
	{
		if (current[i] != '%')
		{
			m = m + ft_putchar(current[i]);
			i++;
		}
		else
		{
			i++;
			m += ft_fct(current[i], args);
			i++;
		}
	}
	return (m);
}
