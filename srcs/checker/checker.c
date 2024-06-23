/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:32:05 by cimy              #+#    #+#             */
/*   Updated: 2024/06/23 17:40:04 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;
	char	*gnl;

	gnl = "";
	check_arg(argc, argv);
	if (argc >= 2)
		argv = ft_double_strjoin(&argv[1]);
	if (error_handling(argv) == 1)
		return (1);
	setup_stack(&head_a, &head_b, argv);
	if (count_stack_length(head_a) == 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	while (1)
	{
		gnl = get_next_line(0);
		if (!gnl)
			break ;
		if (is_instruction(gnl) == false)
			return (ft_putstr_fd("Error\n", 2),
				free_node(head_a), free_node(head_b), free(gnl), 1);
		do_instruction(head_a, head_b, gnl);
		free(gnl);
	}
	judge_kok(gnl, head_a, head_b);
}
