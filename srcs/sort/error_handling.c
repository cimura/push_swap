/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:29 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 15:43:06 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

int	error_handling(char **argv)
{
	int			i;
	long long	num;

	i = 0;
	if (check_duplicate_num(argv) == false)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (argv[i] != NULL)
	{
		num = ft_atol(argv[i]);
		if (!check_string_is_num(argv[i]) || !check_num(num))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

bool	check_num(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

bool	check_string_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!is_num(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_duplicate_num(char **num_array)
{
	int	i;
	int	j;
	int	sign1;
	int	sign2;
	int	size;

	i = 0;
	size = count_num_array(num_array);

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			sign1 = is_sign(num_array[i][0]);
			sign2 = is_sign(num_array[j][0]);
			if (ft_strncmp(&num_array[i][sign1], &num_array[j][sign2]
												, INT_MAX) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
