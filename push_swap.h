/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:53:55 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/15 22:03:17 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_s
{
	int				content;
	struct stack_s	*next;
}					t_stack;

int					ft_printf(char *s, ...);
long long			ft_atoi(const char *theString);
void				reverse_rotate(t_stack **a);
void				rotate(t_stack **a);
void				swap(t_stack **a);
void				push_in_stack_a(t_stack **a, t_stack **b, int *tab,
						int *index);
void				push_in_stack_b(t_stack **b, t_stack **a, int *tab,
						int *index);
int					max_value_stack(t_stack *a);
t_stack				*min_value_stack(t_stack **a);
void				tri_tree(t_stack **a, int *tab, int *index);
void				tri_more_tree(t_stack **a, t_stack **b, int *tab,
						int *index);
void				verify_action_a(t_stack **a, int x, int *tab, int *index);
void				verify_action_b(t_stack **b, int x, int *tab, int *index);
int					taille_stack(t_stack *a);
int					cost_node(t_stack *a, int x);
void				ft_lstadd_back_(t_stack **lst, t_stack *new);
char				**ft_split(const char *s, char c);
t_stack				*ft_lstnew_(int content);
int					cost_rr(t_stack *a, int x, t_stack *b, int y);
size_t				ft_strlen(const char *theString);
void				free_memory(char **st);
int					ft_repetition(t_stack *a);
int					ft_err(char *str);
int					valid_str(char *str);
int					is_sorted(t_stack *a);
void				ft_tab_rrr(int *tab, int *k, int index);
void				ft_tab_rr(int *tab, int *k, int index);
void				ft_ghh(int n, int h, int fg);
void				ft_fdd(int n, int h, int fg);
int					ft_preciser_rotate(int *h, int *e, int *fg, int *n);
void				tri_tab(int *tab, int size);
int					*create_tab(t_stack *a);
void				push_on_stack_b_new(t_stack **a, t_stack **b, int *tab,
						int *index);
void				ft_remplir_tab(int val, int *tab, int *index);
void				ft_lstclear(t_stack *lst);

#endif
