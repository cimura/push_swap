/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/07 18:22:18 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void sa(t_node *head_a)
{
	int tmp;

	tmp = head_a->next->data;
	head_a->next->data = head_a->next->next->data;
	head_a->next->next->data = tmp;

	ft_putstr_fd("sa\n", 1);
}

void ra(t_node *head_a)
{
	if (head_a->next == head_a || head_a->prev == head_a)
		return;
	t_node *first = head_a->next;
	t_node *second = first->next;
	t_node *last = head_a->prev;

	head_a->next = second;
	second->prev = head_a;

	last->next = first;
	first->prev = last;
	first->next = head_a;
	head_a->prev = first;

	ft_putstr_fd("ra\n", 1);
}

void rra(t_node *head_a)
{
	if (head_a->next == head_a || head_a->prev == head_a)
		return;
	t_node *first = head_a->next;
	t_node *second = first->next;
	t_node *last = head_a->prev;

	head_a->next = first;
	second->prev = head_a;

	last->next = first;
	first->prev = last;
	second->next = head_a;
	head_a->next = last;

	ft_putstr_fd("rra\n", 1);
}

void pa(t_node *head_a, t_node *head_b)
{
	t_node *a_first = head_a->next;
	t_node *b_first = head_b->next;

	head_b->next = b_first->next;
	head_a->next = b_first;
	b_first->next = a_first;
	ft_putstr_fd("pa\n", 1);
}

int find_cheapest_num(t_node *head_a, t_node *head_b, int indx)
{
	int	forward_count = 1;
	int back_count = 1;

	t_node *current_a = go_x_steps(head_a, indx);
	t_node *current_b = head_b->next;

	while (1)
	{
		// max 谷を見つける
		if (current_b->data <= current_b->next->data && current_a->data > current_b->data)
			break ;
		// ハマるところを見つける
		if (current_a->data < current_b->data && current_a->data >= current_b->next->data)
			break ;
		current_b = current_b->next;
		forward_count++;
	}
	current_b = head_b->prev;

	while (1)
	{
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
		return (forward_count);
	return (back_count);
}

t_operations *check_stack_a(t_node *head_a, t_node *head_b)
{
	int i = 0;
	t_operations *operations;
	operations = malloc(sizeof(t_operations));
	operations->b_rotation = 1;
	int	current_count;
	int min_count = INT_MAX;
	while (i < 4)
	{
		current_count = find_cheapest_num(head_a, head_b, i);
		if (current_count < 0)
		{
			operations->b_rotation = -1;
			current_count *= -1;
		}
		current_count += i;
		printf("current_count: %d\n\n", current_count);
		if (current_count < min_count)
		{
			min_count = current_count;
			operations->a_indx = i;
		}
		i++;
	}
	operations->b_count = min_count;
	return (operations);
}