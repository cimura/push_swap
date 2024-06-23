/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:09 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/23 17:39:04 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

bool	is_instruction(char *str)
{
	if (!ft_strncmp("pa\n", str, 3))
		return (true);
	else if (!ft_strncmp("pb\n", str, 3))
		return (true);
	else if (!ft_strncmp("sa\n", str, 3))
		return (true);
	else if (!ft_strncmp("sb\n", str, 3))
		return (true);
	else if (!ft_strncmp("ss\n", str, 3))
		return (true);
	else if (!ft_strncmp("ra\n", str, 3))
		return (true);
	else if (!ft_strncmp("rb\n", str, 3))
		return (true);
	else if (!ft_strncmp("rrr\n", str, 4))
		return (true);
	else if (!ft_strncmp("rra\n", str, 4))
		return (true);
	else if (!ft_strncmp("rrb\n", str, 4))
		return (true);
	else if (!ft_strncmp("rr\n", str, 3))
		return (true);
	return (false);
}

void	do_instruction(t_node *head_a, t_node *head_b, char *str)
{
	if (!ft_strncmp("pa\n", str, 3))
		return (pa(&head_a, &head_b, false));
	else if (!ft_strncmp("pb\n", str, 3))
		return (pb(&head_a, &head_b, false));
	else if (!ft_strncmp("sa\n", str, 3))
		return (sa(&head_a, false));
	else if (!ft_strncmp("sb\n", str, 3))
		return (sb(&head_b, false));
	else if (!ft_strncmp("ss\n", str, 3))
		return (sa(&head_a, false), sb(&head_b, false));
	else if (!ft_strncmp("ra\n", str, 3))
		return (ra(&head_a, false));
	else if (!ft_strncmp("rb\n", str, 3))
		return (rb(&head_b, false));
	else if (!ft_strncmp("rrr\n", str, 4))
		return (rrr(&head_a, &head_b, false));
	else if (!ft_strncmp("rra\n", str, 4))
		return (rra(&head_a, false));
	else if (!ft_strncmp("rrb\n", str, 4))
		return (rrb(&head_b, false));
	else if (!ft_strncmp("rr\n", str, 3))
		return (rr(&head_a, &head_b, false));
}

int	judge_kok(char *gnl, t_node *head_a, t_node *head_b)
{
	if (!gnl)
		free(gnl);
	if (is_sorted(head_a) == false)
	{
		ft_putstr_fd("KO\n", 1);
		free_node(head_a);
		free_node(head_b);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("OK\n", 1);
	free_node(head_a);
	free_node(head_b);
	exit(EXIT_SUCCESS);
}
