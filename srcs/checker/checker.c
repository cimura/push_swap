/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:32:05 by cimy              #+#    #+#             */
/*   Updated: 2024/06/17 09:01:13 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

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

bool	is_instruction(char *str)
{
	if (str[0] == 'p' && str[1] == 'a')
		return (true);
	else if (str[0] == 'p' && str[1] == 'b')
		return (true);
	if (str[0] == 's' && str[1] == 'a')
		return (true);
	else if (str[0] == 's' && str[1] == 'b')
		return (true);
	else if (str[0] == 's' && str[1] == 's')
		return (true);
	else if (str[0] == 'r' && str[1] == 'a')
		return (true);
	else if (str[0] == 'r' && str[1] == 'b')
		return (true);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		return (true);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		return (true);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		return (true);
	else if (str[0] == 'r' && str[1] == 'r')
		return (true);
	return (false);
}

void	do_instruction(t_node *head_a, t_node *head_b, char *str)
{
	if (str[0] == 'p' && str[1] == 'a')
		return (pa(&head_a, &head_b, false));
	else if (str[0] == 'p' && str[1] == 'b')
		return (pb(&head_a, &head_b, false));
	if (str[0] == 's' && str[1] == 'a')
		return (sa(&head_a, false));
	else if (str[0] == 's' && str[1] == 'b')
		return (sb(&head_b, false));
	else if (str[0] == 's' && str[1] == 's')
		return (sa(&head_a, false), sb(&head_b, false));
	else if (str[0] == 'r' && str[1] == 'a')
		return (ra(&head_a, false));
	else if (str[0] == 'r' && str[1] == 'b')
		return (rb(&head_b, false));
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		return (rrr(&head_a, &head_b, false));
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		return (rra(&head_a, false));
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		return (rrb(&head_b, false));
	else if (str[0] == 'r' && str[1] == 'r')
		return (rr(&head_a, &head_b, false));
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;
	char	*gnl;

	gnl = "";
	if (argc == 1)
		return (0);
	else if (argc >= 2)
		argv = ft_double_strjoin(&argv[1]);
	if (error_handling(argv) == 1)
		return (1);
	setup_stack(&head_a, &head_b, argv);
	while (1)
	{
		gnl = get_next_line(0);
		if (!gnl)
			break ;
		if (is_instruction(gnl) == false)
		{
			ft_putstr_fd("Error\n", 2);
			free_node(head_a);
			free_node(head_b);
			free(gnl);
			exit(1);
		}
		do_instruction(head_a, head_b, gnl);
		free(gnl);
	}
	judge_kok(gnl, head_a, head_b);
}

int	judge_kok(char *gnl, t_node *head_a, t_node *head_b)
{
	if (!gnl)
		free(gnl);
	if (is_sorted(head_a) == true
	&& (head_b->next == head_b || head_b->prev == head_b))
	{
		ft_putstr_fd("OK\n", 1);
		free_node(head_a);
		free_node(head_b);
		exit(0);
	}
	ft_putstr_fd("KO\n", 1);
	free_node(head_a);
	free_node(head_b);
	exit(0);
}
