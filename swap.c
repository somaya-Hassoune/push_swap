/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:52:24 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/16 16:12:35 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*suivant;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	suivant = (*a)->next;
	(*a)->next = (*a)->next->next;
	suivant->next = (*a);
	(*a) = suivant;
}
