/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:33:53 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:29:25 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*temp;
	t_stack	*suivant;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	temp = (*a);
	last = (*a);
	suivant = (*a)->next;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
	(*a) = suivant;
}
