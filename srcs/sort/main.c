/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:18 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/23 17:10:22 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;

	if (argc == 1)
		return (0);
	else if (argc >= 2)
		argv = ft_double_strjoin(&argv[1]);
	if (error_handling(argv) == 1)
		return (1);
	setup_stack(&head_a, &head_b, argv);
	if (is_sorted(head_a) == true)
		return (free_node(head_a), free_node(head_b), 0);
	if (count_stack_length(head_a) == 0)
		return (free_node(head_a), free_node(head_b), no_nodes_print());
	else if (count_stack_length(head_a) == 1)
		return (free_node(head_a), free_node(head_b), 0);
	else if (count_stack_length(head_a) == 2)
		return (handle_two(&head_a), free_node(head_a), free_node(head_b), 0);
	else if (count_stack_length(head_a) == 3)
		return (handle_three(&head_a), free_node(head_a), free_node(head_b), 0);
	push_swap(&head_a, &head_b);
	free_node(head_a);
	free_node(head_b);
	return (0);
}
