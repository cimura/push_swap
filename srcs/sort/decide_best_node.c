/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_best_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:28:47 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 12:27:59 by sshimura         ###   ########.fr       */
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

// void	decide_push_cost(t_node **head_a, t_node **head_b)
// {
// 	t_node	*current;
// 	t_node	*target;

// 	current = (*head_a)->next;
// 	while (current != (*head_a))
// 	{
// 		(*head_a)->now_cost
// 			= calculate_push_cost(*head_a, current, false);
// 		target = find_target_pb(*head_b, current);
// 		(*head_b)->now_cost
// 			= calculate_push_cost(*head_b, target, false);
// 		update_push_cost(head_a, head_b, &current, &target);
// 		current = current->next;
// 	}
// }

// void	update_push_cost(t_node **head_a, t_node **head_b,
// 						t_node **current, t_node **target)
// {
// 	int	cost_mine;
// 	int	now_count;
// 	int	a_cost;
// 	int	b_cost;

// 	a_cost = (*head_a)->now_cost;
// 	b_cost = (*head_b)->now_cost;

// 	cost_mine = INT_MAX;
// 	if (!a_cost && !b_cost
// 		&& (*head_a)->is_clock == (*head_b)->is_clock)
// 		now_count = max(a_cost, b_cost);
// 	else
// 		now_count = a_cost + b_cost;
// 	if (cost_mine > now_count)
// 	{
// 		(*head_a)->push_cost = calculate_push_cost(*head_a, *current, true);
// 		(*head_b)->push_cost = calculate_push_cost(*head_b, *target, true);
// 		cost_mine = now_count;
// 	}
// }

void	decide_push_cost(t_node **head_a, t_node **head_b)
{
	t_node	*current;
	t_node	*target;
	int		cost_mine;
	int		now_count;

	current = (*head_a)->next;
	cost_mine = INT_MAX;
	while (current != (*head_a))
	{
		(*head_a)->now_cost = calculate_push_cost(*head_a, current, false);
		target = find_target_pb(*head_b, current);
		(*head_b)->now_cost = calculate_push_cost(*head_b, target, false);
		if ((*head_a)->now_cost != 0 && (*head_b)->now_cost != 0
			&& (*head_a)->is_clock == (*head_b)->is_clock)
		now_count = max((*head_a)->now_cost, (*head_b)->now_cost);
		else
			now_count = (*head_a)->now_cost + (*head_b)->now_cost;
		if (cost_mine > now_count)
		{
			(*head_a)->push_cost = calculate_push_cost(*head_a, current, true);
			(*head_b)->push_cost = calculate_push_cost(*head_b, target, true);
			cost_mine = now_count;
		}
		current = current->next;
	}
}
