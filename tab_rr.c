/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 03:07:01 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:28:47 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_preciser_rotate(int *h, int *e, int *fg, int *n)
{
	int	m;

	m = 0;
	if (*h < *e)
	{
		*n = *h;
		m = *e - *h;
		*fg = 1;
	}
	else
	{
		*n = *e;
		m = *h - *e;
	}
	return (m);
}

void	ft_fdd(int n, int h, int fg)
{
	int	e;

	e = 0;
	while (e < n)
	{
		ft_printf("rr\n");
		e++;
	}
	while (h >= 1)
	{
		if (fg == 1)
			ft_printf("rb\n");
		else
			ft_printf("ra\n");
		h--;
	}
}

void	ft_ghh(int n, int h, int fg)
{
	int	e;

	e = 0;
	while (e < n)
	{
		ft_printf("rrr\n");
		e++;
	}
	while (h >= 1)
	{
		if (fg == 1)
			ft_printf("rrb\n");
		else
			ft_printf("rra\n");
		h--;
	}
}

void	ft_tab_rr(int *tab, int *k, int index)
{
	int	e;
	int	h;
	int	fg;
	int	n;

	h = 0;
	e = 0;
	fg = 0;
	n = 0;
	if ((tab[*k] == 4 || tab[*k] == 5))
	{
		while (*k < index && (tab[*k] == 4 || tab[*k] == 5))
		{
			if (tab[*k] == 4)
				h++;
			else if (tab[*k] == 5)
				e++;
			(*k)++;
		}
		h = ft_preciser_rotate(&h, &e, &fg, &n);
		ft_fdd(n, h, fg);
	}
}

void	ft_tab_rrr(int *tab, int *k, int index)
{
	int	e;
	int	h;
	int	fg;
	int	n;

	h = 0;
	e = 0;
	fg = 0;
	n = 0;
	if ((tab[*k] == 6 || tab[*k] == 7))
	{
		while (*k < index && (tab[*k] == 6 || tab[*k] == 7))
		{
			if (tab[*k] == 6)
				h++;
			else if (tab[*k] == 7)
				e++;
			(*k)++;
		}
		h = ft_preciser_rotate(&h, &e, &fg, &n);
		ft_ghh(n, h, fg);
	}
}
