/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/07 16:06:32 by sshimura         ###   ########.fr       */
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
}				t_node;

typedef struct s_operatons
{
	char	*operations;
	int		data;
}				t_operations;


void	ft_putstr_fd(char *s, int fd);

void	sa(t_node *head_a);
void	ra(t_node *head_a);
void	rra(t_node	*head_a);
void	pa(t_node *head_a, t_node *head_b);
int		find_cheapest_num(t_node *head_a, t_node *head_b, int indx);
int		check_stack_a(t_node *head_a, t_node *head_b);

void	sb(t_node *head_b);
void	rb(t_node *head_b);
void	rrb(t_node	*head_b);
void	pb(t_node *head_a, t_node *head_b);

t_node	*create_node(int data);
t_node	*initialize_stack();
void	add_node(t_node *head, int data);
void	print_list(t_node *head);
int		count_list_nodes(t_node *head);
t_node	*go_x_steps(t_node *head, int num);

void	three_optical(t_node *head_a);

# endif