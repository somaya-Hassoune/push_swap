/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_more_than_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:57:24 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/01 23:52:26 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*fd_target(t_stack **a, int x)
{
	t_stack	*temp2;
	t_stack	*target;
	size_t	result;
	size_t	k;

	while (*a && (*a)->content < x)
		(*a) = (*a)->next;
	result = (size_t)((*a)->content - x);
	target = *a;
	temp2 = *a;
	while (temp2)
	{
		if (temp2->content > x)
		{
			k = temp2->content - x;
			if ((k <= result))
			{
				target = temp2;
				result = k;
			}
		}
		temp2 = temp2->next;
	}
	return (target);
}

static t_stack	*find_target(t_stack **a, int x)
{
	t_stack	*target;
	t_stack	*temp;

	temp = (*a);
	if (x > max_value_stack(*a))
		target = min_value_stack(a);
	else
	{
		target = fd_target(&temp, x);
	}
	return (target);
}

static void	traitement(t_stack **a, t_stack **b, int *tab, int *index)
{
	t_stack	*temp;
	int		cost;
	t_stack	*element;
	t_stack	*target;
	t_stack	*target_temp;

	target = find_target(a, (*b)->content);
	cost = cost_rr((*a), target->content, (*b), (*b)->content);
	temp = (*b);
	while (temp)
	{
		target_temp = find_target(a, temp->content);
		if (cost_rr((*a), target_temp->content, (*b), temp->content) <= cost)
		{
			cost = cost_rr((*a), target_temp->content, (*b), temp->content);
			target = target_temp;
			element = temp;
		}
		temp = temp->next;
	}
	verify_action_a(a, target->content, tab, index);
	verify_action_b(b, element->content, tab, index);
	push_in_stack_b(b, a, tab, index);
}

void	tri_more_tree(t_stack **a, t_stack **b, int *tab, int *index)
{
	t_stack	*min;

	if (taille_stack(*a) > 5)
		push_on_stack_b_new(a, b, tab, index);
	while (taille_stack(*a) > 3)
	{
		push_in_stack_a(a, b, tab, index);
	}
	tri_tree(a, tab, index);
	while ((*b))
	{
		traitement(a, b, tab, index);
	}
	min = min_value_stack(a);
	verify_action_a(a, min->content, tab, index);
}
