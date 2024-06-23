/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:40:34 by cimy              #+#    #+#             */
/*   Updated: 2024/06/23 17:39:52 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "node.h"

// in gnl
char	*get_next_line(int fd);

// in checker_util.c
void	check_arg(int argc, char **argv);
bool	is_instruction(char *str);
void	do_instruction(t_node *head_a, t_node *head_b, char *str);
int		judge_kok(char *gnl, t_node *head_a, t_node *head_b);

#endif