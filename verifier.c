/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:04:28 by shassoun          #+#    #+#             */
/*   Updated: 2024/03/30 21:30:55 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(char **st)
{
	int	j;

	j = 0;
	while (st[j])
	{
		free(st[j]);
		j++;
	}
	free(st);
}

int	ft_repetition(t_stack *a)
{
	t_stack	*temp;

	temp = a->next;
	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (temp->content == a->content)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (1);
	}
	return (0);
}

int	valid_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
	{
		i++;
	}
	if (ft_strlen(str + i) >= 11)
		return (1);
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		return (1);
	temp = a;
	while (temp->next && temp->content < temp->next->content)
	{
		temp = temp->next;
	}
	if (temp->next)
		return (0);
	return (1);
}
