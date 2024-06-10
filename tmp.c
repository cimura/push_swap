#include "node.h"

int main() {
	// 4 3 12 10 8 7 5
	// t_node *head_a = initialize_stack();
	t_node *head_b = initialize_stack();

	add_node(&head_b, 4);
	add_node(&head_b, 3);
	add_node(&head_b, 12);
	add_node(&head_b, 10);
	add_node(&head_b, 8);
	add_node(&head_b, 7);
	add_node(&head_b, 5);
	// add_node(&head_b, 2);
	// add_node(&head_b, 13);
	// add_node(&head_b, 15);
	// add_node(&head_b, 9);
	// add_node(&head_b, 14);

	// add_node(&head_b, 5);
	// add_node(&head_b, 7);

	printf("---b--\n");
	print_list(head_b);

	rrb(&head_b);

	// printf("-- a ---\n");
	// print_list(head_b);
	printf("---b--\n");
	print_list(head_b);
}