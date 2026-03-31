/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:56:54 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/16 19:09:30 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_instruct(char *st, t_stack **a, t_stack **b)
{
	int	index;
	int	*tab;

	index = -1;
	tab = NULL;
	if (ft_strncmp(st, "ra\n", 4) == 0 || ft_strncmp(st, "rr\n", 4) == 0)
		rotate(a);
	if (ft_strncmp(st, "rb\n", 4) == 0 || ft_strncmp(st, "rr\n", 4) == 0)
		rotate(b);
	if (ft_strncmp(st, "rra\n", 5) == 0 || ft_strncmp(st, "rrr\n", 5) == 0)
		reverse_rotate(a);
	if (ft_strncmp(st, "rrb\n", 5) == 0 || ft_strncmp(st, "rrr\n", 5) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(st, "pa\n", 4) == 0)
		push_in_stack_b(b, a, tab, &index);
	else if (ft_strncmp(st, "pb\n", 4) == 0)
		push_in_stack_a(a, b, tab, &index);
	else if (ft_strncmp(st, "ra\n", 4) != 0 && ft_strncmp(st, "rr\n", 4) != 0
		&& ft_strncmp(st, "rb\n", 4) != 0 && ft_strncmp(st, "rra\n", 5) != 0)
		display_err(st);
}

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

int	test(t_stack *a, t_stack *b)
{
	char	*st;

	st = NULL;
	if (ft_repetition(a) == 1)
		return (write(2, "Error\n", 6), ft_lstclear(a), 1);
	st = get_next_line(0);
	while (st)
	{
		if (ft_strncmp(st, "sa\n", 4) == 0 || ft_strncmp(st, "ss\n", 4) == 0)
			swap(&a);
		if (ft_strncmp(st, "sb\n", 4) == 0 || ft_strncmp(st, "ss\n", 4) == 0)
			swap(&b);
		else if (ft_strncmp(st, "sa\n", 4) != 0)
			ft_instruct(st, &a, &b);
		free(st);
		st = get_next_line(0);
	}
	if (is_sorted(a) == 1 && taille_stack(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}

int	abc(char **str, t_stack **a)
{
	int	j;

	j = 0;
	if (str[0] == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (str[j])
	{
		check_error(a, str[j]);
		j++;
	}
	return (j);
}

int	main(int acc, char **argv)
{
	int		i;
	t_stack	*a;
	char	**str;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (acc > 1)
	{
		while (argv[i])
		{
			str = ft_split(argv[i], ' ');
			abc(str, &a);
			free_memory(str);
			i++;
		}
		if (test(a, b) == 1)
			exit(1);
	}
}
