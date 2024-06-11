#include "node.h"

// first-->  5 2 7 1 6 3 9 4 8

// stack a
// 7 1 6 3 9 4 8

// stack b
// 2 5

int main(){
	t_node	*head_a = initialize_stack();
	t_node	*head_b = initialize_stack();

	add_node(&head_a, 6);
	add_node(&head_a, 3);
	add_node(&head_a, 9);
	add_node(&head_a, 4);
	add_node(&head_a, 8);
	add_node(&head_a, 2);
	add_node(&head_a, 1);

	add_node(&head_b, 5);
	add_node(&head_b, 7);
	// add_node(&head_b, 5);
	// add_node(&head_b, 2);


	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);

// input -> 4

// -- a ---
// 6 3 9 4 8
// ---b--
// 1 7 5 2
// target->data 2
// count-> 1
// rotaion-> -1
// ここからわかる通り、targetのnodeを見つけること、それを引数として
// 先頭に持ってくるコストを計算することもできる。回転の向きも構造体で持っている
// あとはそのコストに基づいてどのnodeをpushするかを決め、ループで回す

// 追記...t_operationsを作らなくても、t_nodeに回転やインデックスを持たせればいっか！！

	// t_operations *operation = malloc(sizeof(t_operations));

	// t_node *target = find_target(head_a->next->next->next->next, head_b);
	// printf("target->data\t->\t%d\n", target->data);
	// int count = calculate_push_cost(head_b, target, operation);
	// printf("count\t\t->\t%d\n", count);
	// printf("rotation\t->\t%d\n", operation->rotation);

	// t_operations *operation = malloc(sizeof(t_operations));

	// 現在の位置
	t_node	*current = head_a->next;
	int	cost_mine;
	int	now_count;

while (count_stack_length(head_a) != 3)
{
	cost_mine = INT_MAX;
	current = head_a->next;
	while (current != head_a)
	{
		head_a->to_push = calculate_push_cost(head_a, current);
		t_node *target = find_target(head_b, current);
		head_b->to_push = calculate_push_cost(head_b, target);

		now_count = head_a->to_push + head_b->to_push;

		printf("\x1b[33mtarget->data: %d\n\n\x1b[39m", target->data);
		// printf("\x1b[33mtarget->data: %d\n\n\x1b[39m", target->data);
		// printf("now_count->data\t->\t%d\n\n", now_count);

		if (cost_mine > now_count)
		{

			head_a->indx = calculate_push_cost(head_a, current);
			head_b->indx = calculate_push_cost(head_b, target);
			// printf("\x1b[33ma_indx: %d\n\n\x1b[39m", head_a->indx);
			// printf("\x1b[33mb_indx: %d\n\n\x1b[39m", head_b->indx);
			cost_mine = now_count;
		}
		current = current->next;
	}

	// printf("\x1b[32mPass\n\n\x1b[39m");

	int i = 0;
	while (i < head_a->indx)
	{
		if (head_a->rotation == -1)
			rra(&head_a);
		else
			ra(&head_a);
		i++;
	}
	printf("\x1b[32mPass %d \n\n\x1b[39m", head_b->rotation);

	i = 0;
	while (i < head_b->indx)
	{
		if (head_b->rotation == -1)
			rrb(&head_b);
		else
			rb(&head_b);
		i++;
	}
	pb(&head_a, &head_b);

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);
}
	// printf("current->data\t->\t%d\n\n", current->data);

	// t_node *target = find_target(head_a->next->next->next, head_b);
	// printf("target->data\t->\t%d\n", target->data);
	// int count = calculate_push_cost(head_b, target);
	// printf("count\t\t->\t%d\n", count);
	// printf("rotation\t->\t%d\n", head_b->rotation);

	// int i = 0;
	// while (i < head_a->indx)
	// {
	// 	if (head_a->rotation == -1)
	// 		rra(&head_a);
	// 	else
	// 		ra(&head_a);
	// 	i++;
	// }

	// i = 0;
	// while (i < head_b->indx)
	// {
	// 	if (head_b->rotation == -1)
	// 		rrb(&head_b);
	// 	else
	// 		rb(&head_b);
	// 	i++;
	// }
	// pb(&head_a, &head_b);

	// printf("-- a ---\n");
	// print_list(head_a);
	// printf("---b--\n");
	// print_list(head_b);
}