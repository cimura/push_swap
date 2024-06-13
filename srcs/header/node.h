/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 14:05:27 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	NODE_H
# define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../../libft/libft.h"
#include <stdbool.h>

typedef	struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				now_cost;
	int				push_cost;
	int				push_data;
	int				rotation;
	bool			is_clock;
}				t_node;

// in libft/
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int	whitespace(char check_chr);
int	decide_sign(const char *str, int *indx);
// in operation_to_a.c
void			sa(t_node **head_a);
void			ra(t_node **head_a, bool overwrite_enabled);
void			rra(t_node	**head_a, bool overwrite_enabled);
void			pa(t_node **head_a, t_node **head_b);
t_node	*find_target_pb(t_node *head_b, t_node *pos_a);
t_node	*find_target_pa(t_node *head_a, t_node *pos_b);
// int				find_cheapest_num(t_node **head_a, t_node **head_b, int indx);
// t_node		*check_stack_a(t_node **head_a, t_node **head_b);

// in operation_to_b.c
void	sb(t_node **head_b);
void	rb(t_node **head_b, bool overwrite_enabled);
void	rrb(t_node	**head_b, bool overwrite_enabled);
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
// t_node	*find_last_node(t_node *head);
int	max(int a, int b);

// in calculate_push_cost.c
int	calculate_push_cost(t_node *head, t_node *pos, bool overwrite_enabled);

// rr, rrr
void	rr(t_node **head_a, t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);

// in rotation.c
void	perform_ab_rotations(t_node *head_a, t_node *head_b);
void	perform_a_rotations(t_node *head_a);
void	perform_b_rotations(t_node *head_b);
void	rotation_push(t_node *head_a, t_node *head_b, bool is_push_a);
void	last_rotation(t_node *head_a);

// in error_handling.c
bool	is_num(char c);
bool	check_string_is_num(char *str);
bool	check_num(long long num);
long long	ft_atol(const char *str);
bool	check_duplicate_num(char **num_array);
int	count_num_array(char **num_array);

void	setup_stack(t_node **head_a, t_node **head_b, char **num_array);

// in decide_best_node.c
void	decide_push_cost_toa(t_node **head_a, t_node **head_b);
void	decide_push_cost_tob(t_node **head_a, t_node **head_b);

# endif