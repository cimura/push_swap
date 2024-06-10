/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/10 15:04:07 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	sb(t_node **head_b)
{
	int	tmp;

	tmp = (*head_b)->next->data;
	(*head_b)->next->data = (*head_b)->next->next->data;
	(*head_b)->next->next->data = tmp;

	ft_putstr_fd("sb\n", 1);
}

void	rb(t_node **head_b)
{
	if ((*head_b)->next == (*head_b) || (*head_b)->prev == (*head_b))
		return ;
	t_node	*first = (*head_b)->next;
	t_node	*second = first->next;
	t_node	*last = (*head_b)->prev;


	(*head_b)->next = second;
	second->prev = (*head_b);

	last->next = first;
	first->prev = last;
	first->next = (*head_b);
	(*head_b)->prev = first;

	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_node	**head_b)
{
	if ((*head_b)->next == (*head_b) || (*head_b)->prev == (*head_b))
		return ;
	t_node	*first = (*head_b)->next;
	t_node	*last = (*head_b)->prev;
	t_node	*last_second = last->prev;

	(*head_b)->next = last;
	last->prev = (*head_b);
	last->next = first;

	(*head_b)->prev = last_second;
	last_second->next = (*head_b);

	ft_putstr_fd("rrb\n", 1);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*a_first = (*head_a)->next;
	t_node	*b_first = (*head_b)->next;

	(*head_a)->next = a_first->next;
	(*head_b)->next = a_first;

	a_first->next = b_first;
	b_first->prev = a_first;
	ft_putstr_fd("pb\n", 1);
}