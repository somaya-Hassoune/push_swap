/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:17:36 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/08 12:31:36 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_node(t_stack *a, int x)
{
	t_stack	*temp;
	int		i;
	int		n;
	int		cost;

	temp = a;
	i = 1;
	n = taille_stack(a);
	while (temp && temp->content != x)
	{
		temp = temp->next;
		i++;
	}
	if (i <= (n / 2) + 1)
	{
		cost = i - 1;
	}
	else
		cost = n - i + 1;
	return (cost);
}
