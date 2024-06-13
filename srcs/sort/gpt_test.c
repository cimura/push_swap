/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:18 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 15:54:13 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = ft_split((const char *)argv[1], ' ');
	else
		argv = &argv[1];
	if (error_handling(argv) == 1)
		return (1);
	setup_stack(&head_a, &head_b, argv);

	if (count_stack_length(head_a) == 0 || count_stack_length(head_a) == 1)
		return (0);
	else if (count_stack_length(head_a) == 2)
		return (handle_two_nodes(&head_a));
	else if (count_stack_length(head_a) == 3)
		return (handle_three_nodes(&head_a));

	push_swap(&head_a, &head_b);
	return (0);
}
