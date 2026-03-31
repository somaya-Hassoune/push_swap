/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_stackk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:16:38 by shassoun          #+#    #+#             */
/*   Updated: 2024/03/28 02:45:32 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value_stack(t_stack *a)
{
	t_stack	*temp;
	int		max;

	temp = a;
	max = a->content;
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
		}
		temp = temp->next;
	}
	return (max);
}
