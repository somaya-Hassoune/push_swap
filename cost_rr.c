/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:44:53 by shassoun          #+#    #+#             */
/*   Updated: 2024/03/30 18:04:07 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max(int a, int b)
{
	if (a >= b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

int	caluler_cost(t_stack *a, t_stack *b, int i, int j)
{
	if ((i <= (taille_stack(a) / 2) + 1) && (j <= (taille_stack(b) / 2) + 1))
	{
		return (max((i - 1), (j - 1)));
	}
	else if ((i > (taille_stack(a) / 2) + 1) && (j > (taille_stack(b) / 2) + 1))
	{
		return (max((taille_stack(a) - i + 1), (taille_stack(b) - j + 1)));
	}
	else
	{
		return (-1);
	}
}

int	cost_rr(t_stack *a, int x, t_stack *b, int y)
{
	t_stack	*temp;
	int		i;
	int		j;
	int		m;

	temp = a;
	i = 1;
	j = 1;
	while (temp && temp->content != x)
	{
		temp = temp->next;
		i++;
	}
	temp = b;
	while (temp && temp->content != y)
	{
		temp = temp->next;
		j++;
	}
	m = (caluler_cost(a, b, i, j));
	if (m == -1)
		return (cost_node(a, x) + cost_node(b, y));
	else
		return (m);
}
