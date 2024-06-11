/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/11 17:35:13 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void sa(t_node **head_a)
{
	int tmp;

	tmp = (*head_a)->next->data;
	(*head_a)->next->data = (*head_a)->next->next->data;
	(*head_a)->next->next->data = tmp;

	ft_putstr_fd("sa\n", 1);
}

void ra(t_node **head_a, int rewrite_enabled)
{
	if ((*head_a)->next == (*head_a) || (*head_a)->prev == (*head_a))
		return;
	t_node *first = (*head_a)->next;
	t_node *second = first->next;
	t_node *last = (*head_a)->prev;

	(*head_a)->next = second;
	second->prev = (*head_a);

	first->next = (*head_a);
	(*head_a)->prev = first;
	last->next = first;
	first->prev = last;

	if (rewrite_enabled == 1)
		ft_putstr_fd("ra\n", 1);
}

void rra(t_node **head_a, int rewrite_enabled)
{
	if ((*head_a)->next == (*head_a) || (*head_a)->prev == (*head_a))
		return;
	t_node *first = (*head_a)->next;
	t_node *last = (*head_a)->prev;
	t_node *last_second = last->prev;

	(*head_a)->prev = last_second;
	last_second->next = (*head_a);

	(*head_a)->next = last;
	last->prev = (*head_a);
	last->next = first;
	first->prev = last;

	if (rewrite_enabled == 1)
		ft_putstr_fd("rra\n", 1);
}

void pa(t_node **head_a, t_node **head_b)
{
	t_node *a_first = (*head_a)->next;

	t_node *b_first = (*head_b)->next;
	t_node *b_second = b_first->next;

	(*head_b)->next = b_second;
	b_second->prev = (*head_b);

	(*head_a)->next = b_first;
	b_first->prev = (*head_a);

	b_first->next = a_first;
	a_first->prev = b_first;
	ft_putstr_fd("pa\n", 1);
}

// 前から見てtargetを見つける関数
// これを基にpushコストを計算できるが、構造体でどちらに回転すべきかの情報を
// 持っておかないといけない

t_node	*find_target_pb(t_node *head_b, t_node *pos_a)
{
	t_node	*max_node_b;
	t_node	*min_node_b;
	t_node	*current = head_b->next;
	t_node	*target = head_b->next;
	int		diff = INT_MAX;

	max_node_b = find_max_node(head_b);
	min_node_b = find_min_node(head_b);
	if (pos_a->data < min_node_b->data)
		return (max_node_b);
	while (current != head_b)
	{
		if (diff > pos_a->data - current->data && pos_a->data - current->data > 0)
		{
			diff = pos_a->data - current->data;
			target = current;
		}
		// if (pos_a->data > current->data && current->data >= current->next->data)
		// 	target = current;
		// if (diff > 0 && pos_a->data > current->data)
		// 	target = current;
		current = current->next;
	}
	return (target);
}

t_node	*find_target_pa(t_node *head_a, t_node *pos_b)
{
	t_node	*max_node_a;
	t_node	*min_node_a;
	t_node	*current = head_a->next;
	t_node	*target = head_a->next;
	int		diff = INT_MAX;

	max_node_a = find_max_node(head_a);
	min_node_a = find_min_node(head_a);
	if (pos_b->data > max_node_a->data)
		return (min_node_a);
	while (current != head_a)
	{
		if (diff > current->data - pos_b->data && current->data - pos_b->data > 0)
		{
			diff = current->data - pos_b->data;
			target = current;
		}
		current = current->next;
	}
	return (target);
}