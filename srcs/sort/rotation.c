/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:45:32 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/16 15:45:59 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	perform_ab_rotations(t_node *head_a, t_node *head_b)
{
	while (head_a->push_cost != 0 && head_b->push_cost != 0)
	{
		if (head_a->rotation == head_b->rotation && head_a->rotation == -1)
			rrr(&head_a, &head_b, true);
		else if (head_a->rotation == head_b->rotation && head_a->rotation == 1)
			rr(&head_a, &head_b, true);
		else
			break ;
		head_a->push_cost--;
		head_b->push_cost--;
	}
}

void	perform_a_rotations(t_node *head_a)
{
	int	i;

	i = 0;
	while (i < head_a->push_cost)
	{
		if (head_a->rotation == -1)
			rra(&head_a, true);
		else
			ra(&head_a, true);
		i++;
	}
}

void	perform_b_rotations(t_node *head_b)
{
	int	i;

	i = 0;
	while (i < head_b->push_cost)
	{
		if (head_b->rotation == -1)
			rrb(&head_b, true);
		else
			rb(&head_b, true);
		i++;
	}
}

void	rotation_push(t_node *head_a, t_node *head_b, bool is_push_a)
{
	perform_ab_rotations(head_a, head_b);
	perform_a_rotations(head_a);
	perform_b_rotations(head_b);
	if (is_push_a == true)
		return (pa(&head_a, &head_b, true));
	return (pb(&head_a, &head_b, true));
}

void	last_rotation(t_node *head_a)
{
	int	i;

	i = 0;
	if (head_a->rotation == -1)
		head_a->push_cost--;
	while (i < head_a->push_cost)
	{
		if (head_a->rotation == -1)
			rra(&head_a, true);
		else
			ra(&head_a, true);
		i++;
	}
	if (head_a->rotation == 1)
		ra(&head_a, true);
}
