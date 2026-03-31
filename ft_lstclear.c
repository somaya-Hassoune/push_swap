/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:38:47 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/07 02:24:45 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack *lst)
{
	t_stack	*suiv;

	if (!lst)
		return ;
	while (lst)
	{
		suiv = (lst)->next;
		free(lst);
		lst = suiv;
	}
}
