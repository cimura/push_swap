/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_two_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:53:33 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 14:48:17 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

// int	**make_num_array(char **num_str)
// {
// 	int	num_array;

// 	num_array = 
// }

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

int	handle_four_nodes(t_node **head_a, t_node **head_b)
{
	t_node	*current;

	pb(head_a, head_b);
	handle_three_nodes(head_a);
	pa(head_a, head_b);
	current = (*head_a)->next;
	// while (current != (*head_a))
	// {
	// 	if (current->data < current->next->data)
	// 		ra(head_a, 0);
	// 	current = current->next;
	// }
	print_list(*head_a);
	return (0);
}
