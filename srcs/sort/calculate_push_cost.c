/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_push_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:41 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/16 13:45:03 by sshimura         ###   ########.fr       */
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
	if (count > lstsize / 2)
	{
		head->is_clock = true;
		if (overwrite_enabled == 1)
			head->rotation = 1;
		return (lstsize - count);
	}
	if (overwrite_enabled == 1)
		head->rotation = -1;
	head->is_clock = false;
	return (count);
}
