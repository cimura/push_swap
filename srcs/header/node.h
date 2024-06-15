/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/15 20:14:40 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../../libft/libft.h"
// #include "../../get_next_line/get_next_line.h"
#include <stdbool.h>

typedef	struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	long				data;
	int				now_cost;
	int				push_cost;
	// int				push_data;
	int				rotation;
	bool			is_clock;
}				t_node;

// in libft/
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int	whitespace(char check_chr);
int	decide_sign(const char *str, int *indx);

// in gnl
char	*get_next_line(int fd);

// in operation_to_a.c
void			sa(t_node **head_a, bool print);
void			ra(t_node **head_a, bool print);
void			rra(t_node	**head_a, bool print);
void			pa(t_node **head_a, t_node **head_b, bool print);
t_node	*find_target_pb(t_node *head_b, t_node *pos_a);
t_node	*find_target_pa(t_node *head_a, t_node *pos_b);
// int				find_cheapest_num(t_node **head_a, t_node **head_b, int indx);
// t_node		*check_stack_a(t_node **head_a, t_node **head_b);

// in operation_to_b.c
void	sb(t_node **head_b, bool print);
void	rb(t_node **head_b, bool print);
void	rrb(t_node	**head_b, bool print);
void	pb(t_node **head_a, t_node **head_b, bool print);

// in operation_list.c
t_node	*create_node(long data);
t_node	*initialize_stack();
void	add_node(t_node **head, long data);
void	print_list(t_node *head);
int		count_stack_length(t_node *head);

// in sort_small_stacks.c
int	handle_two_nodes(t_node **head_a);
int	handle_three_nodes(t_node **head_a);

// basic_utils_list.c
t_node	*find_max_node(t_node *head);
t_node	*find_min_node(t_node *head);
// t_node	*find_last_node(t_node *head);
long	max(long a, long b);

// in calculate_push_cost.c
int	calculate_push_cost(t_node *head, t_node *pos, bool overwrite_enabled);

// rr, rrr
void	rr(t_node **head_a, t_node **head_b, bool print);
void	rrr(t_node **head_a, t_node **head_b, bool print);

// in rotation.c
void	perform_ab_rotations(t_node *head_a, t_node *head_b);
void	perform_a_rotations(t_node *head_a);
void	perform_b_rotations(t_node *head_b);
void	rotation_push(t_node *head_a, t_node *head_b, bool is_push_a);
void	last_rotation(t_node *head_a);

// in error_handling.c
bool	check_string_is_num(char *str);
bool	check_num(long num);
bool	check_duplicate_num(char **num_array);
int	error_handling(char **argv);

// in util_error_handling.c
bool	is_num(char c);
int	count_num_array(char **num_array);
long	ft_atol(const char *str);
int	is_sign(char c);
int	no_nodes_print(void);


void	setup_stack(t_node **head_a, t_node **head_b, char **num_array);

// in decide_best_node.c
void	decide_push_cost_toa(t_node **head_a, t_node **head_b);
void	decide_push_cost_tob(t_node **head_a, t_node **head_b);

// in push_swap.c
void	push_swap(t_node **head_a, t_node **head_b);
void	final_rotation(t_node **head_a);

// in to_substring.c
// int	count_double_ptr(char **argv);
int	count_dwords(char  **s, char c);
char	**ft_double_strjoin(char **argv);

# endif