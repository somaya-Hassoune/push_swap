/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:27:16 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/14 14:56:13 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	table_val(int val, int *tab, int *index)
{
	tab[*index] = val;
	(*index)++;
}

void	ft_remplir_tab(int val, int *tab, int *index)
{
	if (*index == -4)
	{
		if (val == 1)
			ft_printf("pa\n");
		else if (val == 2)
			ft_printf("pb\n");
		else if (val == 3)
			ft_printf("sa\n");
		if (val == 4)
			ft_printf("ra\n");
		if (val == 5)
			ft_printf("rb\n");
		if (val == 6)
			ft_printf("rra\n");
		if (val == 7)
			ft_printf("rrb\n");
	}
	else if (*index != -1)
	{
		table_val(val, tab, index);
	}
}
