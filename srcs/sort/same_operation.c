/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/14 15:29:06 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	rr(t_node **head_a, t_node **head_b, bool print)
{
	if (print == true)
	{
		ra(head_a, true);
		rb(head_b, true);
		ft_putstr_fd("rr\n", 1);
	}
	ra(head_a, false);
	rb(head_b, false);
}

void	rrr(t_node **head_a, t_node **head_b, bool print)
{
	if (print == true)
	{
		rra(head_a, true);
		rrb(head_b, true);
		ft_putstr_fd("rrr\n", 1);
	}
		rra(head_a, false);
		rrb(head_b, false);
}
