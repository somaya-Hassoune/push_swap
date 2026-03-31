/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:43:50 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/16 16:11:14 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_err(char *st)
{
	if (ft_strncmp(st, "ra\n", 4) != 0 && ft_strncmp(st, "rb\n", 4) != 0
		&& ft_strncmp(st, "rr\n", 4) != 0 && ft_strncmp(st, "pa\n", 4) != 0
		&& ft_strncmp(st, "pb\n", 4) != 0
		&& ft_strncmp(st, "sa\n", 4) != 0 && ft_strncmp(st, "sb\n", 4) != 0
		&& ft_strncmp(st, "rra\n", 5) != 0 && ft_strncmp(st, "rrb\n", 5) != 0
		&& ft_strncmp(st, "rrr\n", 5) != 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
