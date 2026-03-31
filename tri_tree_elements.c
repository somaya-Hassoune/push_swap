/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_tree_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:09:31 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:27:40 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_stack(t_stack *a)
{
	t_stack	*temp;
	int		i;
	int		max;
	int		index;

	temp = a;
	i = 1;
	max = a->content;
	index = 1;
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
			index = i;
		}
		i++;
		temp = temp->next;
	}
	return (index);
}

void	tri_tree(t_stack **a, int *tab, int *index)
{
	if (max_stack(*a) == 1)
	{
		rotate(a);
		ft_remplir_tab(4, tab, index);
	}
	else if (max_stack(*a) == 2)
	{
		reverse_rotate(a);
		ft_remplir_tab(6, tab, index);
	}
	if ((*a)->content > (*a)->next->content)
	{
		swap(a);
		ft_remplir_tab(3, tab, index);
	}
}
