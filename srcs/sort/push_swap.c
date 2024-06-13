/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:36:42 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 15:52:01 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	push_swap(t_node **head_a, t_node **head_b)
{
	pb(head_a, head_b);
	// pbするところまでやる
	while (count_stack_length(*head_a) != 3)
	{
		decide_push_cost_toa(head_a, head_b);
		rotation_push(*head_a, *head_b, false);
	}
	handle_three_nodes(head_a);
	// pa(push back), stack b が空になるまでstack aにpushする

	while (count_stack_length(*head_b) != 0)
	{
		decide_push_cost_tob(head_a, head_b);
		rotation_push(*head_a, *head_b, true);
	}
	final_rotation(head_a);
}

void	final_rotation(t_node **head_a)
{
	t_node	*max_node;

	max_node = find_max_node(*head_a);
	(*head_a)->push_cost = calculate_push_cost(*head_a, max_node, true);
	last_rotation(*head_a);
}
