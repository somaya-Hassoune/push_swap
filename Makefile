# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 23:59:31 by shassoun          #+#    #+#              #
#    Updated: 2024/04/17 16:16:09 by shassoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -fsanitize=address -g3

SRCS = push_in_stack_a.c reverse_rotate.c rotate.c swap.c tri_tree_elements.c verify_action_a.c \
 verify_action_b.c tri_more_than_tree.c taille_stack.c push_in_stack_b.c min_value_stack.c max_stackk.c \
ft_split.c ft_new_node.c ft_atoi.c cost.c add_node.c ft_strlen.c cost_rr.c ./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c main.c verifier.c tab_rr.c tri_tab.c meduim.c cases_tab.c ft_lstclear.c

SRCS_BONUS = checker.c push_in_stack_b.c push_in_stack_a.c ft_strlen.c ./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c reverse_rotate.c rotate.c swap.c ft_split.c ft_new_node.c ft_atoi.c add_node.c \
verifier.c display_err_bonus.c taille_stack.c ft_lstclear.c cases_tab.c ft_strncmp.c

ftprintf = printf/libftprintf.a

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
$(NAME):$(OBJS) $(ftprintf)
	$(CC) $(CFLAGS)  $(OBJS) $(ftprintf) -o $(NAME)

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_BONUS)  $(ftprintf)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(ftprintf) -o $(NAME_BONUS)

$(ftprintf):
	make -C ./printf

clean :
	make fclean -C ./printf
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean 
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all 

.PHONY: clean




