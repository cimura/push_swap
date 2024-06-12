/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:51:01 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 14:51:27 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"
#include "../../libft/libft.h"

void	handle_three_nodes(t_node *head_a)
{
	t_node	*current;
	t_node	*max_node;

	current = head_a->next;
	max_node = find_max_node(head_a);
	if (max_node == current)
		ra(&head_a, 1);
	else if (max_node == head_a->next->next)
		rra(&head_a, 1);
	current = head_a->next;
	if (current->data > current->next->data)
		sa(&head_a);
}
