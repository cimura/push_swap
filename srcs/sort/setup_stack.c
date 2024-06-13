/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:52:45 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 12:49:13 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	setup_stack(t_node **head_a, t_node **head_b, char **argv)
{
	int	i;

	*head_a = initialize_stack();
	*head_b = initialize_stack();
	i = 0;
	while (argv[i] != NULL)
	{
		add_node(head_a, ft_atoi(argv[i]));
		i++;
	}
}
