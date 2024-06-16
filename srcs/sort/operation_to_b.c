/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/16 15:48:02 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	sb(t_node **head_b, bool print)
{
	long	tmp;

	tmp = (*head_b)->next->data;
	(*head_b)->next->data = (*head_b)->next->next->data;
	(*head_b)->next->next->data = tmp;
	if (print == true)
		ft_putstr_fd("sb\n", 1);
}

void	rb(t_node **head_b, bool print)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if ((*head_b)->next == (*head_b) || (*head_b)->prev == (*head_b))
		return ;
	first = (*head_b)->next;
	second = first->next;
	last = (*head_b)->prev;
	(*head_b)->next = second;
	second->prev = (*head_b);
	last->next = first;
	first->prev = last;
	first->next = (*head_b);
	(*head_b)->prev = first;
	if (print == true)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_node	**head_b, bool print)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_second;

	if ((*head_b)->next == (*head_b) || (*head_b)->prev == (*head_b))
		return ;
	first = (*head_b)->next;
	last = (*head_b)->prev;
	last_second = last->prev;
	(*head_b)->prev = last_second;
	last_second->next = (*head_b);
	(*head_b)->next = last;
	last->prev = (*head_b);
	last->next = first;
	first->prev = last;
	if (print == true)
		ft_putstr_fd("rrb\n", 1);
}

void	pb(t_node **head_a, t_node **head_b, bool print)
{
	t_node	*a_first;
	t_node	*b_first;
	t_node	*a_second;

	a_first = (*head_a)->next;
	b_first = (*head_b)->next;
	a_second = a_first->next;
	(*head_a)->next = a_second;
	a_second->prev = (*head_a);
	(*head_b)->next = a_first;
	a_first->prev = (*head_b);
	a_first->next = b_first;
	b_first->prev = a_first;
	if (print == true)
		ft_putstr_fd("pb\n", 1);
}

t_node	*find_target_pa(t_node *head_a, t_node *pos_b)
{
	t_node	*max_node_a;
	t_node	*min_node_a;
	t_node	*current;
	t_node	*target;
	long	diff;

	current = head_a->next;
	target = head_a->next;
	diff = LONG_MAX;
	max_node_a = find_max_node(head_a);
	min_node_a = find_min_node(head_a);
	if (pos_b->data > max_node_a->data)
		return (min_node_a);
	while (current != head_a)
	{
		if (diff > current->data - pos_b->data
			&& current->data - pos_b->data > 0)
		{
			diff = current->data - pos_b->data;
			target = current;
		}
		current = current->next;
	}
	return (target);
}
