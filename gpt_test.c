#include "node.h"

// first-->  5 2 7 1 6 3 9 4 8

// stack a
// 7 1 6 3 9 4 8

// stack b
// 2 5

int main(int argc, char *argv[])
{
	t_node *head_a = initialize_stack();
	t_node *head_b = initialize_stack();

	int i = 1;
	while (argv[i] != NULL)
	{
		add_node(&head_a, atoi(argv[i]));
		i++;
	}
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);

	// add_node(&head_a, 8);
	// add_node(&head_a, 3);
	// add_node(&head_a, 12);
	// add_node(&head_a, 10);
	// add_node(&head_a, 4);
	// add_node(&head_a, 6);
	// add_node(&head_a, 11);
	// add_node(&head_a, 2);
	// add_node(&head_a, 13);
	// add_node(&head_a, 15);
	// add_node(&head_a, 9);
	// add_node(&head_a, 14);

	// add_node(&head_b, 5);
	// add_node(&head_b, 7);

	// printf("-- a ---\n");
	// print_list(head_a);
	// printf("---b--\n");
	// print_list(head_b);

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
			head_a->current_push_cost = calculate_push_cost(head_a, current, false);
			target = find_target_pb(head_b, current);
			head_b->current_push_cost = calculate_push_cost(head_b, target, false);
			if ((head_a->current_push_cost != 0 && head_a->current_push_cost != 0) && head_a->is_clockwise == head_b->is_clockwise)
				now_count = max(head_a->current_push_cost, head_b->current_push_cost);
			else
				now_count = head_a->current_push_cost + head_b->current_push_cost;

			if (cost_mine > now_count)
			{
				// printf("in a loop and cost is -> %d", now_count);
				head_a->push_data = current->data;
				head_b->push_data = target->data;
				head_a->push_cost = calculate_push_cost(head_a, current, true);
				head_b->push_cost = calculate_push_cost(head_b, target, true);
				cost_mine = now_count;

				// printf("\x1b[36mCurrent node->data: %d\n", head_a->push_data);
				// printf("Target node->data: %d\n", target->data);

				// printf("Current A cost: %d\n", head_a->push_cost);
				// printf("Current B cost: %d\n", head_b->push_cost);

				// printf("Rotation for A: %d, Rotation for B: %d\n", head_a->rotation, head_b->rotation);
				// printf("\x1b[39m\n");
			}
			current = current->next;
		}


		while (head_a->push_cost != 0 && head_b->push_cost != 0)
		{
			// printf("\n\n\x1b[33m in a loop \n\n\x1b[m");
			if (head_a->rotation == head_b->rotation && head_a->rotation == -1)
			{
				rrr(&head_a, &head_b);
			}
			else if (head_a->rotation == head_b->rotation && head_a->rotation == 1)
			{
				rr(&head_a, &head_b);
			}
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
		// printf("\x1b[32mRotated A %d times\n", head_a->push_cost);
		// printf("\x1b[39m");

		i = 0;
		while (i < head_b->push_cost)
		{
			if (head_b->rotation == -1)
				rrb(&head_b, 1);
			else
				rb(&head_b, 1);
			i++;
		}
		// printf("\x1b[32mRotated B %d times\n", head_b->push_cost);
		// printf("\x1b[39m");

		// printf("\n-- Before pb --\n");
		// printf("-- a ---\n");
		// print_list(head_a);
		// printf("---b--\n");
		// print_list(head_b);

		pb(&head_a, &head_b);

		// printf("\n-- After pb --\n");
		// printf("-- a ---\n");
		// print_list(head_a);
		// printf("---b--\n");
		// print_list(head_b);
	}
	// printf("\n\n -------- time to push back -------- \n\n");

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

				// printf("\x1b[36mCurrent node->data: %d\n", head_b->push_data);
				// printf("Target node->data: %d\n", target->data);

				// printf("Current A cost: %d\n", head_a->push_cost);
				// printf("Current B cost: %d\n", head_b->push_cost);

				// printf("Rotation for A: %d, Rotation for B: %d\n", head_a->rotation, head_b->rotation);
				// printf("\x1b[39m\n");
			}
			current = current->next;
			// if (current == head_a)
			// 	break ;
		}

		// printf("\n\n\x1b[32m head_a->push cost: %d \n\n\x1b[m", head_a->push_cost);
		// printf("\n\n\x1b[32m head_b->push cost: %d \n\n\x1b[m", head_b->push_cost);


		while (head_a->push_cost != 0 && head_b->push_cost != 0)
		{
			// printf("\n\n\x1b[33m in a loop \n\n\x1b[m");
			if (head_a->rotation == head_b->rotation && head_a->rotation == -1)
			{
				rrr(&head_a, &head_b);
			}
			else if (head_a->rotation == head_b->rotation && head_a->rotation == 1)
			{
				rr(&head_a, &head_b);
			}
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
		// printf("\x1b[32mRotated A %d times\n", head_a->push_cost);
		// printf("\x1b[39m");

		i = 0;
		while (i < head_b->push_cost)
		{
			if (head_b->rotation == -1)
				rrb(&head_b, 1);
			else
				rb(&head_b, 1);
			i++;
		}
		// printf("\x1b[32mRotated B %d times\n", head_b->push_cost);
		// printf("\x1b[39m");

		// printf("\n-- Before pa --\n");
		// printf("-- a ---\n");
		// print_list(head_a);
		// printf("---b--\n");
		// print_list(head_b);

		pa(&head_a, &head_b);

		// printf("\n-- After pa --\n");
	}

	i = 0;
	t_node *now = head_a->next;

	t_node	*max_node = find_max_node(head_a);
	head_a->push_cost = calculate_push_cost(head_a, max_node, true);
	if (head_a->rotation == -1)
		head_a->push_cost--;
	while (i < head_a->push_cost)
	{
		// printf("head_a->rotation: %d\n", head_a->rotation);
		if (head_a->rotation == -1)
			rra(&head_a, 1);
		else
			ra(&head_a, 1);
		i++;
	}
	if (head_a->rotation == 1)
		ra(&head_a, 1);

		// printf("-- a ---\n");
		// print_list(head_a);
		// printf("---b--\n");
		// print_list(head_b);

	return 0;
}
