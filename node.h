/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/09 16:35:24 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	NODE_H
# define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

typedef	struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				to_push;
	int				a_indx;
	int				rotation;
}				t_node;

// typedef struct s_operatons
// {
// 	// int	b_to_top;
// 	int	push_cost;
// 	int rotation;
// }				t_operations;

// in libft/
void	ft_putstr_fd(char *s, int fd);

// in operation_to_a.c
void			sa(t_node **head_a);
void			ra(t_node **head_a);
void			rra(t_node	**head_a);
void			pa(t_node **head_a, t_node **head_b);
int				find_cheapest_num(t_node **head_a, t_node **head_b, int indx);
t_node		*check_stack_a(t_node **head_a, t_node **head_b);

// in operation_to_b.c
void	sb(t_node **head_b);
void	rb(t_node **head_b);
void	rrb(t_node	**head_b);
void	pb(t_node **head_a, t_node **head_b);

// in operation_list.c
t_node	*create_node(int data);
t_node	*initialize_stack();
void	add_node(t_node **head, int data);
void	print_list(t_node *head);
int		count_stack_length(t_node *head);
t_node	*go_x_steps(t_node **head, int num);

// in three_numbers.c
void	handle_three_nodes(t_node *head_a);


// basic_utils_list.c
t_node	*find_max_node(t_node *head);
t_node	*find_min_node(t_node *head);
t_node	*find_last_node(t_node *head);
t_node	*find_target(t_node	*pos_a, t_node *head_b);

// in calculate_push_cost.c
int	calculate_push_cost(t_node *head, t_node *pos);

# endif