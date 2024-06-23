/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:30:51 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/15 20:14:26 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = decide_sign(str, &i);
	result = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign > 0)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	count_num_array(char **num_array)
{
	int	count;

	count = 0;
	while (num_array[count] != NULL)
		count++;
	return (count);
}

int	is_sign(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	no_nodes_print(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}
