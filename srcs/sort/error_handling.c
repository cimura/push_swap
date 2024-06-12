/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:29 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 14:57:15 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

// 何も入力がない場合（実行ファイルのみ）は何も表示しない
// エラーの場合は"標準エラー出力" に "Error\n"と出力する

char	**tune_input(char *argv)
{
	char	**chr_num_array;

	chr_num_array = ft_split(argv[1], ' ');
	return (chr_num_array);
}

// 42\0 11\0 9\0 NULL

bool	check_num(int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (false);
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	check_string_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_num(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	check_arg(int argc, char *argv[])
{
	print_error(check_argc(argc, argv));
	if (argc == 2)

}

int	check_argc(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	return (0);
}

void	print_error(int flag)
{
	if (flag == 1)
		return ;
	else if (flag == -1)
		ft_putstr_fd("Error\n", 2);
}

// "12  42 34 12"

// "
// 12\0
// 42\0
// 34\0
// 12\0
// NULL
// "