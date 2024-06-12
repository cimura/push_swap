/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:18 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 14:58:14 by sshimura         ###   ########.fr       */
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
	int i = 0;
	// エラーハンドリング（引数の数）
	// check_argc(argcの値によって操作を変える)
	int	flag = check_arg(argc, argv);
	print_list(flag);

	// 渡すための数値作成

	// stackの作成
	argc = 0;

	t_node *head_a;
	t_node *head_b;

	char	**num_array = tune_input(argv);
	setup_stack(&head_a, &head_b, num_array);

	pb(&head_a, &head_b);
	pb(&head_a, &head_b);

	t_node *current;
	int cost_mine;
	int now_count;
	t_node *target;

	while (count_stack_length(head_a) != 3)
	{
		cost_mine = INT_MAX;
		current = head_a->next;
		while (current != head_a)
		{
			head_a->current_push_cost = calculate_push_cost(head_a, current, false);
			target = find_target_pb(head_b, current);
			head_b->current_push_cost = calculate_push_cost(head_b, target, false);
			if ((head_a->current_push_cost != 0 && head_a->current_push_cost != 0) && head_a->is_clockwise == head_b->is_clockwise)
				now_count = max(head_a->current_push_cost, head_b->current_push_cost);
			else
				now_count = head_a->current_push_cost + head_b->current_push_cost;

			if (cost_mine > now_count)
			{
				head_a->push_data = current->data;
				head_b->push_data = target->data;
				head_a->push_cost = calculate_push_cost(head_a, current, true);
				head_b->push_cost = calculate_push_cost(head_b, target, true);
				cost_mine = now_count;
			}
			current = current->next;
		}


		while (head_a->push_cost != 0 && head_b->push_cost != 0)
		{
			if (head_a->rotation == head_b->rotation && head_a->rotation == -1)
				rrr(&head_a, &head_b);
			else if (head_a->rotation == head_b->rotation && head_a->rotation == 1)
				rr(&head_a, &head_b);
			else
				break;
			head_a->push_cost--;
			head_b->push_cost--;
		}


		int i = 0;
		while (i < head_a->push_cost)
		{
			if (head_a->rotation == -1)
				rra(&head_a, 1);
			else
				ra(&head_a, 1);
			i++;
		}

		i = 0;
		while (i < head_b->push_cost)
		{
			if (head_b->rotation == -1)
				rrb(&head_b, 1);
			else
				rb(&head_b, 1);
			i++;
		}
		pb(&head_a, &head_b);
	}
	handle_three_nodes(head_a);

	/*----------------------------------------------*/
	/*												*/
	/*												*/
	/*												*/
	/*----------------------------------------------*/

	// pa(push back), stack b が空になるまでstack aにpushする

	while (count_stack_length(head_b) != 0)
	{
		cost_mine = INT_MAX;
		current = head_b->next;
		while (current != head_b)
		{
			head_b->current_push_cost = calculate_push_cost(head_b, current, false);
			target = find_target_pa(head_a, current);
			head_a->current_push_cost = calculate_push_cost(head_a, target, false);
			now_count = head_a->current_push_cost + head_b->current_push_cost;

			if (cost_mine > now_count)
			{
				head_a->push_data = target->data;
				head_b->push_data = current->data;
				head_a->push_cost = calculate_push_cost(head_a, target, true);
				head_b->push_cost = calculate_push_cost(head_b, current, true);
				cost_mine = now_count;
			}
			current = current->next;
		}

		while (head_a->push_cost != 0 && head_b->push_cost != 0)
		{
			if (head_a->rotation == head_b->rotation && head_a->rotation == -1)
				rrr(&head_a, &head_b);
			else if (head_a->rotation == head_b->rotation && head_a->rotation == 1)
				rr(&head_a, &head_b);
			else
				break;
			head_a->push_cost--;
			head_b->push_cost--;
		}

		int i = 0;
		while (i < head_a->push_cost)
		{
			if (head_a->rotation == -1)
				rra(&head_a, 1);
			else
				ra(&head_a, 1);
			i++;
		}

		i = 0;
		while (i < head_b->push_cost)
		{
			if (head_b->rotation == -1)
				rrb(&head_b, 1);
			else
				rb(&head_b, 1);
			i++;
		}

		pa(&head_a, &head_b);
	}

	i = 0;

	t_node	*max_node = find_max_node(head_a);
	head_a->push_cost = calculate_push_cost(head_a, max_node, true);
	if (head_a->rotation == -1)
		head_a->push_cost--;
	while (i < head_a->push_cost)
	{
		if (head_a->rotation == -1)
			rra(&head_a, 1);
		else
			ra(&head_a, 1);
		i++;
	}
	if (head_a->rotation == 1)
		ra(&head_a, 1);
	return 0;
}
