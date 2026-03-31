/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:23:42 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/16 19:01:38 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(t_stack **a, char *str)
{
	long long	nb;

	if (ft_err(str) == 1 || valid_str(str) == 1)
	{
		write(2, "Error\n", 6);
		ft_lstclear(*a);
		exit(1);
	}
	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < INT_MIN)
	{
		write(2, "Error\n", 6);
		ft_lstclear(*a);
		exit(1);
	}
	if ((*a) == NULL)
		(*a) = ft_lstnew_(nb);
	else
		ft_lstadd_back_(a, ft_lstnew_(nb));
}

int	abc(char **str, t_stack **a)
{
	int	j;

	j = 0;
	if (str[0] == NULL)
	{
		write(2, "Error\n", 6);
		ft_lstclear(*a);
		exit(1);
	}
	while (str[j])
	{
		check_error(a, str[j]);
		j++;
	}
	return (j);
}

void	ft_organiser_tab(int *tab, int index)
{
	int	k;

	k = 0;
	while (k < index)
	{
		ft_tab_rr(tab, &k, index);
		ft_tab_rrr(tab, &k, index);
		if (tab[k] == 1)
			ft_printf("pa\n");
		else if (tab[k] == 2)
			ft_printf("pb\n");
		else if (tab[k] == 3)
			ft_printf("sa\n");
		if (tab[k] == 1 || tab[k] == 2 || tab[k] == 3)
			k++;
	}
}

int	ft_base(t_stack *a)
{
	int		*tab;
	int		index;
	t_stack	*b;
	t_stack	*temp;

	index = 0;
	b = NULL;
	temp = a;
	while (temp)
	{
		if (ft_repetition(temp) == 1)
		{
			write(2, "Error\n", 6);
			ft_lstclear(a);
			exit(1);
		}
		temp = temp->next;
	}
	if (is_sorted(a) == 1)
		return (ft_lstclear(a), 0);
	tab = (int *)malloc(sizeof(int) * 9000);
	if (taille_stack(a) >= 550)
		index = -4;
	return (tri_more_tree(&a, &b, tab, &index), ft_organiser_tab(tab, index),
		free(tab), ft_lstclear(a), 0);
}

int	main(int acc, char **argv)
{
	int		i;
	int		j;
	t_stack	*a;
	char	**str;

	i = 1;
	a = NULL;
	if (acc > 1)
	{
		while (argv[i])
		{
			j = 0;
			str = ft_split(argv[i], ' ');
			j = abc(str, &a);
			if (!argv[2] && j < 2)
				j = -1;
			free_memory(str);
			if (j == -1)
				return (ft_lstclear(a), 0);
			i++;
		}
		ft_base(a);
	}
	return (0);
}
