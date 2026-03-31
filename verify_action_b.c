/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_action_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:29:07 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:26:40 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_position_haut(t_stack **b, int x, int *tab, int *index)
{
	while (x != (*b)->content)
	{
		rotate(b);
		ft_remplir_tab(5, tab, index);
	}
}

static void	ft_position_bas(t_stack **b, int x, int *tab, int *index)
{
	while (x != (*b)->content)
	{
		reverse_rotate(b);
		ft_remplir_tab(7, tab, index);
	}
}

void	verify_action_b(t_stack **b, int x, int *tab, int *index)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = (*b);
	i = 1;
	len = taille_stack(*b);
	while (temp && temp->content != x)
	{
		temp = temp->next;
		i++;
	}
	if (i <= len / 2 + 1)
		ft_position_haut(b, x, tab, index);
	else
		ft_position_bas(b, x, tab, index);
}
