/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_action_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:49:44 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/16 16:14:17 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_position_haut(t_stack **a, int x, int *tab, int *index)
{
	while (x != (*a)->content)
	{
		rotate(a);
		ft_remplir_tab(4, tab, index);
	}
}

static void	ft_position_bas(t_stack **a, int x, int *tab, int *index)
{
	while (x != (*a)->content)
	{
		reverse_rotate(a);
		ft_remplir_tab(6, tab, index);
	}
}

void	verify_action_a(t_stack **a, int x, int *tab, int *index)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = (*a);
	i = 1;
	len = taille_stack(*a);
	while (temp && temp->content != x)
	{
		temp = temp->next;
		i++;
	}
	if (i <= len / 2 + 1)
		ft_position_haut(a, x, tab, index);
	else
		ft_position_bas(a, x, tab, index);
}
