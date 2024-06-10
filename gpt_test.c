#include "node.h"

// first-->  5 2 7 1 6 3 9 4 8

// stack a
// 7 1 6 3 9 4 8

// stack b
// 2 5

int main()
{
	t_node *head_a = initialize_stack();
	t_node *head_b = initialize_stack();

	add_node(&head_a, 8);
	add_node(&head_a, 3);
	add_node(&head_a, 12);
	add_node(&head_a, 10);
	add_node(&head_a, 4);
	add_node(&head_a, 6);
	add_node(&head_a, 11);
	add_node(&head_a, 2);
	add_node(&head_a, 13);
	add_node(&head_a, 15);
	add_node(&head_a, 9);
	add_node(&head_a, 14);

	add_node(&head_b, 5);
	add_node(&head_b, 7);

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);

	// 現在の位置
	t_node *current;
	int cost_mine;
	int now_count;
	int rewrite_enabled = 0;
	t_node *target;

	// length_stack a == length_stack b -> boooom!!!!

	while (count_stack_length(head_a) != 3)
	{
		cost_mine = INT_MAX;
		current = head_a->next;
		while (current != head_a)
		{
			head_a->current_push_cost = calculate_push_cost(head_a, current, 0);
			target = find_target(head_b, current);
			head_b->current_push_cost = calculate_push_cost(head_b, target, 0);
			now_count = head_a->current_push_cost + head_b->current_push_cost;

			if (cost_mine > now_count)
			{
				head_a->push_data = current->data;
				head_b->push_data = target->data;
				head_a->push_cost = calculate_push_cost(head_a, current, 1);
				head_b->push_cost = calculate_push_cost(head_b, target, 1);
				cost_mine = now_count;

				printf("\x1b[36mCurrent node->data: %d\n", head_a->push_data);
				printf("Target node->data: %d\n", target->data);

				printf("Current A cost: %d\n", head_a->push_cost);
				printf("Current B cost: %d\n", head_b->push_cost);

				printf("Rotation for A: %d, Rotation for B: %d\n", head_a->rotation, head_b->rotation);
				printf("\x1b[39m\n");
			}
			current = current->next;
			// if (current == head_a)
			// 	break ;
		}

		int i = 0;
		while (i < head_a->push_cost)
		{
			if (head_a->rotation == -1)
				rra(&head_a);
			else
				ra(&head_a);
			i++;
		}
		printf("\x1b[32mRotated A %d times\n", head_a->push_cost);
		printf("\x1b[39m");

		i = 0;
		while (i < head_b->push_cost)
		{
			if (head_b->rotation == -1)
				rrb(&head_b);
			else
				rb(&head_b);
			i++;
		}
		printf("\x1b[32mRotated B %d times\n", head_b->push_cost);
		printf("\x1b[39m");

		printf("\n-- Before pb --\n");
		printf("-- a ---\n");
		print_list(head_a);
		printf("---b--\n");
		print_list(head_b);

		pb(&head_a, &head_b);

		printf("\n-- After pb --\n");
		printf("-- a ---\n");
		print_list(head_a);
		printf("---b--\n");
		print_list(head_b);
	}

	return 0;
}
