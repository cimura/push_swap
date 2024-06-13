/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:18 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/13 14:45:22 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

// first-->  5 2 7 1 6 3 9 4 8

// stack a
// 7 1 6 3 9 4 8

// stack b
// 2 5

/*		--- flow ---		*/

// 1.	argc == 1, argc == 2	
//	エラーハンドリングをする（INT_MIN~INT_MAX, oneやダブりなどの不正な入力）
// 	splitで引数が2つの場合にも対応する

// 2.	引数の数によって条件分岐
// 	1→何もしない
// 	2→swapが必要ならする
// 	3→three_sort
// 	4→普通にソートしていく


int main(int argc, char *argv[])
{
	//int i = 0;
	// エラーハンドリング（引数の数）
	// check_argc(argcの値によって操作を変える)
	// int	flag = check_arg(argc, argv);
	// print_list(flag);

	// 渡すための数値作成

	// char	**num_array = NULL;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = ft_split((const char *)argv[1], ' ');
	else
		argv = &argv[1];

	// +2 2, この場合の重複を修正しないといけない
	bool check = check_duplicate_num(argv);
	if (check == false)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	int i = 0;
	while (argv[i] != NULL)
	{
		long long num = ft_atol(argv[i]);
		if (!check_string_is_num(argv[i]) || !check_num(num))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}

	t_node *head_a;
	t_node *head_b;

	// char	**num_array = tune_input(argv);
	setup_stack(&head_a, &head_b, argv);

	if (count_stack_length(head_a) == 0)
		return (0);
	if (count_stack_length(head_a) == 1)
		return (0);
	else if (count_stack_length(head_a) == 2)
		return (handle_two_nodes(&head_a));
	else if (count_stack_length(head_a) == 3)
		return (handle_three_nodes(&head_a));
	else if (count_stack_length(head_a) == 4)
		return (handle_four_nodes(&head_a, &head_b));
	// else
		// sort_stack();
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);

	// pbするところまでやる

	while (count_stack_length(head_a) != 3)
	{
		decide_push_cost_toa(&head_a, &head_b);
		rotation_push(head_a, head_b, false);
	}
	handle_three_nodes(&head_a);

	// pa(push back), stack b が空になるまでstack aにpushする

	while (count_stack_length(head_b) != 0)
	{
		decide_push_cost_tob(&head_a, &head_b);
		rotation_push(head_a, head_b, true);
	}

	t_node	*max_node = find_max_node(head_a);
	head_a->push_cost = calculate_push_cost(head_a, max_node, true);
	last_rotation(head_a);

	print_list(head_a);
	return 0;
}
