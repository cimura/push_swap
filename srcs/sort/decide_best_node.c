/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_best_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:28:47 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 17:01:28 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

// void	before_three_nodes(t_node *(*head_a), t_node *(*head_b))
// {
// 	t_node	*current;
// 	t_node	*target;
// 	while (count_stack_length((*head_a)) != 3)
// 	{

// 	}
// }

void	check_best_node(t_node **head_a, t_node **head_b)
{
	t_node	*current;
	t_node	*target;
	int		best_count;

	current = (*head_a)->next;
	while (current != (*head_a))
	{
		(*head_a)->current_push_cost = calculate_push_cost(*head_a, current, false);
		target = find_target_pb(*head_b, current);
		(*head_b)->current_push_cost = calculate_push_cost(*head_b, target, false);

		best_count = return_best_count(head_a, head_b, &current, &target);

		current = current->next;
	}
}

int	return_best_count(t_node **head_a, t_node **head_b, t_node **current, t_node **target)
{
	int		cost_mine;
	int		now_count;

	cost_mine = INT_MIN;
	if (((*head_a)->current_push_cost != 0 && (*head_a)->current_push_cost != 0)
		&& (*head_a)->is_clockwise == (*head_b)->is_clockwise)
		now_count = max((*head_a)->current_push_cost, (*head_b)->current_push_cost);
	else
		now_count = (*head_a)->current_push_cost + (*head_b)->current_push_cost;
	if (cost_mine > now_count)
	{
		(*head_a)->push_cost = calculate_push_cost(*head_a, *current, true);
		(*head_b)->push_cost = calculate_push_cost(*head_b, *target, true);
		cost_mine = now_count;
	}
	return (cost_mine);
}