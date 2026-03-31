/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:32:39 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:30:05 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_stack_a(t_stack **a, t_stack **b, int *tab, int *index)
{
	t_stack	*suivant;
	t_stack	*temp;

	if ((*a) == NULL)
		return ;
	temp = (*a);
	suivant = (*a)->next;
	temp->next = (*b);
	(*b) = temp;
	(*a) = suivant;
	ft_remplir_tab(2, tab, index);
}
