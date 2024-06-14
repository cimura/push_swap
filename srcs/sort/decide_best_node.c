/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_best_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:28:47 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/15 02:25:45 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	decide_push_cost_toa(t_node **head_a, t_node **head_b)
{
	t_node	*current;
	t_node	*target;
	int		cost_mine;
	int		now_count;

	current = (*head_b)->next;
	cost_mine = INT_MAX;
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
		if (cost_mine > now_count)
		{
			(*head_a)->push_cost = calculate_push_cost(*head_a, target, true);
			(*head_b)->push_cost = calculate_push_cost(*head_b, current, true);
			cost_mine = now_count;
		}
		printf("Current: %d, Target: %d, Cost: %d\n", current->data, target->data, now_count);
		current = current->next;
	}
	// printf("\na: \n");
	// print_list(*head_a);
	// printf("\nb: \n");
	// print_list(*head_b);
	// printf("\n");
}

void	decide_push_cost_tob(t_node **head_a, t_node **head_b)
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
		printf("Current: %d, Target: %d, Cost: %d\n", current->data, target->data, now_count);

		current = current->next;
	}
	// printf("\na: \n");
	// print_list(*head_a);
	// printf("\nb: \n");
	// print_list(*head_b);
	// printf("\n");
}