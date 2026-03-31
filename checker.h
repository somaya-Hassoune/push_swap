/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:30 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/15 22:03:11 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
char				*get_next_line(int fd);
void				reverse_rotate(t_stack **a);
void				rotate(t_stack **a);
void				swap(t_stack **a);
void				push_in_stack_a(t_stack **a, t_stack **b, int *tab,
						int *index);
void				push_in_stack_b(t_stack **b, t_stack **a, int *tab,
						int *index);
t_stack				*ft_lstnew_(int content);
void				ft_lstadd_back_(t_stack **lst, t_stack *new);
char				**ft_split(const char *s, char c);
size_t				ft_strlen(const char *theString);
void				free_memory(char **st);
int					ft_repetition(t_stack *a);
int					ft_err(char *str);
int					valid_str(char *str);
int					is_sorted(t_stack *a);
void				display_err(char *st);
int					taille_stack(t_stack *a);
void				ft_lstclear(t_stack *lst);
void				ft_remplir_tab(int val, int *tab, int *index);
int					ft_strncmp(const char *str1, const char *str2, size_t n);

#endif