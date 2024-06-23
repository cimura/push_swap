/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:06:17 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/23 16:21:16 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

bool	is_sorted(t_node *head_a)
{
	t_node	*current;

	current = head_a->next;
	while (current->next != head_a)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}
