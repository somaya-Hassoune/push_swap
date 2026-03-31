/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taille_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:20:02 by shassoun          #+#    #+#             */
/*   Updated: 2024/03/30 18:07:42 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	taille_stack(t_stack *a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = a;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
