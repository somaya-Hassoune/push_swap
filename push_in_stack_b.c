/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:35:39 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/02 02:27:28 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_stack_b(t_stack **b, t_stack **a, int *tab, int *index)
{
	t_stack	*suivant;
	t_stack	*temp;

	if ((*b) == NULL)
		return ;
	temp = (*b);
	suivant = (*b)->next;
	temp->next = (*a);
	(*a) = temp;
	(*b) = suivant;
	ft_remplir_tab(1, tab, index);
}
