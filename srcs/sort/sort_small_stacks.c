/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specific_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:53:33 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 15:17:13 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

int	handle_two_nodes(t_node **head_a)
{
	t_node	*x;
	t_node	*y;

	x = (*head_a)->next;
	y = x->next;

	if (x->data > y->data)
		sa(head_a);
	return (0);
}

int	handle_three_nodes(t_node **head_a)
{
	t_node	*current;
	t_node	*max_node;

	current = (*head_a)->next;
	max_node = find_max_node((*head_a));
	if (max_node == current)
		ra(head_a, 1);
	else if (max_node == (*head_a)->next->next)
		rra(head_a, 1);
	current = (*head_a)->next;
	if (current->data > current->next->data)
		sa(head_a);
	return (0);
}