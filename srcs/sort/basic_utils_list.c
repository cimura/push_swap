/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:50 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/15 20:12:45 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

// functions to handle errors

int	count_stack_length(t_node *head)
{
	t_node	*current;
	int		count;

	count = 0;
	current = head->next;
	while (current != head)
	{
		current = current->next;
		count++;
	}
	return (count);
}

// t_node	*find_last_node(t_node *head)
// {
// 	t_node	*current = head;
// 	current = current->prev;
// 	return (current);
// }

t_node	*find_max_node(t_node *head)
{
	t_node	*current;
	t_node	*max_node;

	current = head->next;
	max_node = current;
	while (current != head)
	{
		if (max_node->data < current->data)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_node *head)
{
	t_node	*current;
	t_node	*min_node;

	current = head->next;
	min_node = current;
	while (current != head)
	{
		if (min_node->data > current->data)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

long	max(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}
