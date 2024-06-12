/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_two_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:53:33 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 16:27:29 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

// int	**make_num_array(char **num_str)
// {
// 	int	num_array;

// 	num_array = 
// }

void	handle_two_nodes(t_node *head_a)
{
	t_node	*x;
	t_node	*y;

	x = head_a->next;
	y = x->next;

	if (x->data > y->data)
		sa(&head_a);
	return ;
}