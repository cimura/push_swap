/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:18 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/14 13:54:49 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

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

	if (count_stack_length(head_a) == 0)
		return (free(head_a), free(head_b), no_nodes_print());
	else if (count_stack_length(head_a) == 1)
	{
		// t_node *current = head_a->next;
		// while (current != head_a)
		// {
		// 	free(current);
		// 	current = current->next;
		// }
		return (free(head_a), free(head_b), 0);
	}
	else if (count_stack_length(head_a) == 2)
		return (handle_two_nodes(&head_a));
	else if (count_stack_length(head_a) == 3)
		return (handle_three_nodes(&head_a));

	push_swap(&head_a, &head_b);
	// print_list(head_a);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }