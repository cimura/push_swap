/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:40:34 by cimy              #+#    #+#             */
/*   Updated: 2024/06/17 08:56:18 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "node.h"

bool	is_sorted(t_node *head_a);
bool	is_instruction(char *str);
void	do_instruction(t_node *head_a, t_node *head_b, char *str);
int		judge_kok(char *gnl, t_node *head_a, t_node *head_b);

#endif