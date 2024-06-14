/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:04 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/14 17:08:46 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

void	rr(t_node **head_a, t_node **head_b, bool print)
{
	if (print == true)
	{
		ra(head_a, false);
		rb(head_b, false);
		ft_putstr_fd("rr\n", 1);
	}
	else
	{
		ra(head_a, false);
		rb(head_b, false);
	}
}

void	rrr(t_node **head_a, t_node **head_b, bool print)
{
	if (print == true)
	{
		rra(head_a, false);
		rrb(head_b, false);
		ft_putstr_fd("rrr\n", 1);
	}
	else
	{
		rra(head_a, false);
		rrb(head_b, false);
	}
}
