/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_best_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:28:47 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/16 13:34:27 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	decide_push_cost_toa(t_node **head_a, t_node **head_b)
{
	t_node	*current;
	t_node	*target;
	int		min_count;
	int		now_count;

	current = (*head_b)->next;
	min_count = INT_MAX;
	while (current != (*head_b))
	{
		(*head_b)->now_cost = calculate_push_cost(*head_b, current, false);
		target = find_target_pa(*head_a, current);
		(*head_a)->now_cost = calculate_push_cost(*head_a, target, false);
		if ((*head_a)->now_cost != 0 && (*head_b)->now_cost != 0
			&& (*head_a)->is_clock == (*head_b)->is_clock)
			now_count = max((*head_a)->now_cost, (*head_b)->now_cost);
		else
			now_count = (*head_a)->now_cost + (*head_b)->now_cost;
		if (min_count > now_count)
		{
			(*head_a)->push_cost = calculate_push_cost(*head_a, target, true);
			(*head_b)->push_cost = calculate_push_cost(*head_b, current, true);
			min_count = now_count;
		}
		current = current->next;
	}
}

void	decide_push_cost_tob(t_node **head_a, t_node **head_b)
{
	t_node	*current;
	t_node	*target;
	int		min_count;
	int		now_count;

	current = (*head_a)->next;
	min_count = INT_MAX;
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
		if (min_count > now_count)
		{
			(*head_a)->push_cost = calculate_push_cost(*head_a, current, true);
			(*head_b)->push_cost = calculate_push_cost(*head_b, target, true);
			min_count = now_count;
		}
		current = current->next;
	}
}
