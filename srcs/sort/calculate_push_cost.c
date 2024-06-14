/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_push_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:41 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/15 02:20:28 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

int	calculate_push_cost(t_node *head, t_node *pos, bool overwrite_enabled)
{
	int		count;
	int		lstsize;
	t_node	*current;

	count = 0;
	lstsize = count_stack_length(head);
	current = pos;
	while (current != head)
	{
		current = current->next;
		count++;
	}
	// printf("Calculating push cost: position=%d, count=%d, list size=%d\n", pos->data, count, lstsize);
	if (count > lstsize / 2)
	{
		head->is_clock = true;
		if (overwrite_enabled == 1)
			head->rotation = 1;
		// printf("Returning cost: %d (clockwise)\n", lstsize - count);
		return (lstsize - count);
	}
	if (overwrite_enabled == 1)
		head->rotation = -1;
	head->is_clock = false;
	// printf("Returning cost: %d (counter-clockwise)\n", count);
	return (count);
}
