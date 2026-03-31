/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meduim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:04:56 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:30:36 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_medium(int *tab, int size)
{
	int	med;

	med = size / 2;
	return (tab[med]);
}

int	*create_tab(t_stack *a)
{
	int		size;
	int		*tab;
	t_stack	*temp;
	int		i;

	i = 0;
	size = taille_stack(a);
	tab = (int *)malloc(sizeof(int) * size);
	temp = a;
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	tri_tab(tab, size);
	return (tab);
}

void	push_on_stack_b_new(t_stack **a, t_stack **b, int *tab, int *index)
{
	int	*t;
	int	med;
	int	size;

	t = create_tab(*a);
	size = taille_stack(*a);
	med = find_medium(t, size);
	free(t);
	while (taille_stack(*a) > size / 2)
	{
		if ((*a)->content <= med)
			push_in_stack_a(a, b, tab, index);
		else
		{
			rotate(a);
			ft_remplir_tab(4, tab, index);
		}
	}
}
