/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_value_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:24:09 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:30:20 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_value_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*node_min;
	int		min;

	temp = (*a);
	min = (*a)->content;
	node_min = (*a);
	while (temp)
	{
		if (temp->content < min)
		{
			min = temp->content;
			node_min = temp;
		}
		temp = temp->next;
	}
	return (node_min);
}
