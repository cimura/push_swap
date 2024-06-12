/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 14:50:06 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	ft_putstr_fd("rrr\n", 1);
}