/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:33:36 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:29:41 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*temp;
	t_stack	*before_last;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	temp = (*a);
	last = (*a)->next;
	before_last = (*a);
	while (last->next)
	{
		last = last->next;
		before_last = before_last->next;
	}
	last->next = temp;
	before_last->next = NULL;
	(*a) = last;
}
