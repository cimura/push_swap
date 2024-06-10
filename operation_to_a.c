/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/11 00:41:15 by cimy             ###   ########.fr       */
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

void ra(t_node **head_a)
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

	ft_putstr_fd("ra\n", 1);
}

void rra(t_node **head_a)
{
	if ((*head_a)->next == (*head_a) || (*head_a)->prev == (*head_a))
		return;
	t_node *first = (*head_a)->next;
	t_node *last = (*head_a)->prev;
	t_node *last_second = last->prev;

	(*head_a)->next = last;
	last->prev = (*head_a);
	last->next = first;

	(*head_a)->prev = last_second;
	last_second->next = (*head_a);

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

t_node	*find_target(t_node	*head_b, t_node *pos_a)
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

int find_cheapest_num(t_node **head_a, t_node **head_b, int indx)
{

	// 言い換えるとstack bからtarget_nodeを見つける作業
	// a_nodeと一番近くてより小さいtargetを見つける (a_node > b_node)
	// もし見つからなかったら、targetはmax_b_node (a_node < all_b_nodes)

	int	forward_count = 1;
	int back_count = 1;

	t_node *current_a = go_x_steps(&(*head_a), indx);
	t_node *current_b = (*head_b)->next;

	while (1)
	{
		// ターゲットが最小値の場合
		if (current_b->data <= current_b->next->data && current_a->data < current_b->data)
			break ;
		// max 谷を見つける
		if (current_b->data <= current_b->next->data && current_a->data > current_b->data)
			break ;
		// ハマるところを見つける
		if (current_a->data < current_b->data && current_a->data >= current_b->next->data)
			break ;
		current_b = current_b->next;
		forward_count++;
	}
	current_b = (*head_b)->prev;

	while (1)
	{
		// ターゲットが最小値の場合
		if (current_b->prev->data <= current_b->data && current_a->data < current_b->data)
			break ;
		// max 谷を見つける
		if (current_b->prev->data <= current_b->data && current_a->data > current_b->data)
			break ;
		// ハマるところを見つける
		if (current_a->data > current_b->data && current_a->data <= current_b->prev->data)
			break ;
		current_b = current_b->prev;
		back_count++;
	}
	printf("forward: %d\n", forward_count);
	printf("backword: %d\n", back_count);
	if (forward_count < back_count)
		return (forward_count + indx);
	return (-(back_count + indx));
}

t_node *check_stack_a(t_node **head_a, t_node **head_b)
{
	int i = 0;
	// t_operations *operation;
	// operation = malloc(sizeof(t_operations));
	// operation->rotation = 1;
	int	current_count;
	int min_count = INT_MAX;
	while (i < 4)
	{
		// operation->push_cost = 0;
		current_count = find_cheapest_num(&(*head_a), &(*head_b), i);
		if (current_count < 0)
		{
			// operation->rotation = -1;
			current_count *= -1;
		}
		// current_count += i;
		printf("current_count: %d\n\n", current_count);
		if (current_count < min_count)
		{
			min_count = current_count;
			// operation->a_indx = i;
		}
		printf("min_count: %d\n\n", min_count);

		i++;
	}
	// operation->push_cost = min_count;
	return (*head_a);
}