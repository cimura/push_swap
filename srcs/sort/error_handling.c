/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:29 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 14:05:10 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

bool	check_num(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

// long longを超えるような値に対処する必要があるのか。
// マイナスの処理がめんどくさい

bool	check_string_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!is_num(str[i]))
			return (false);
		i++;
	}
	return (true);
}

long long	ft_atol(const char *str)
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

bool	check_duplicate_num(char **num_array)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = count_num_array(num_array);

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(num_array[i], num_array[j], INT_MAX) == 0)
				return (false);
			j++;

		}
		i++;
	}
	return (true);
}
