/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/16 15:48:28 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	sa(t_node **head_a, bool print)
{
	long	tmp;

	tmp = (*head_a)->next->data;
	(*head_a)->next->data = (*head_a)->next->next->data;
	(*head_a)->next->next->data = tmp;
	if (print == true)
		ft_putstr_fd("sa\n", 1);
}

void	ra(t_node **head_a, bool print)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if ((*head_a)->next == (*head_a) || (*head_a)->prev == (*head_a))
		return ;
	first = (*head_a)->next;
	second = first->next;
	last = (*head_a)->prev;
	(*head_a)->next = second;
	second->prev = (*head_a);
	first->next = (*head_a);
	(*head_a)->prev = first;
	last->next = first;
	first->prev = last;
	if (print == true)
		ft_putstr_fd("ra\n", 1);
}

void	rra(t_node **head_a, bool print)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_second;

	if ((*head_a)->next == (*head_a) || (*head_a)->prev == (*head_a))
		return ;
	first = (*head_a)->next;
	last = (*head_a)->prev;
	last_second = last->prev;
	(*head_a)->prev = last_second;
	last_second->next = (*head_a);
	(*head_a)->next = last;
	last->prev = (*head_a);
	last->next = first;
	first->prev = last;
	if (print == true)
		ft_putstr_fd("rra\n", 1);
}

void	pa(t_node **head_a, t_node **head_b, bool print)
{
	t_node	*a_first;
	t_node	*b_first;
	t_node	*b_second;

	a_first = (*head_a)->next;
	b_first = (*head_b)->next;
	b_second = b_first->next;
	(*head_b)->next = b_second;
	b_second->prev = (*head_b);
	(*head_a)->next = b_first;
	b_first->prev = (*head_a);
	b_first->next = a_first;
	a_first->prev = b_first;
	if (print == true)
		ft_putstr_fd("pa\n", 1);
}

t_node	*find_target_pb(t_node *head_b, t_node *pos_a)
{
	t_node	*max_node_b;
	t_node	*min_node_b;
	t_node	*current;
	t_node	*target;
	long	diff;

	current = head_b->next;
	target = head_b->next;
	diff = LONG_MAX;
	max_node_b = find_max_node(head_b);
	min_node_b = find_min_node(head_b);
	if (pos_a->data < min_node_b->data)
		return (max_node_b);
	while (current != head_b)
	{
		if (diff > pos_a->data - current->data
			&& pos_a->data > current->data)
		{
			diff = pos_a->data - current->data;
			target = current;
		}
		current = current->next;
	}
	return (target);
}
