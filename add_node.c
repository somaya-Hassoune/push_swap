/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:16:52 by shassoun          #+#    #+#             */
/*   Updated: 2024/03/30 21:35:35 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_(t_stack **lst, t_stack *new)
{
	t_stack	*courant;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		courant = *lst;
		while (courant->next)
		{
			courant = courant->next;
		}
		courant->next = new;
	}
}
