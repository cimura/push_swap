#include "node.h"
#include "libft/libft.h"

void handle_three_nodes(t_node *head_a)
{
	t_node	*current = head_a->next;
	t_node	*max_node = find_max_node(head_a);
	if (max_node == current)
		ra(&head_a, 1);
	else if (max_node == head_a->next->next)
		rra(&head_a, 1);
	current = head_a->next;
	if (current->data > current->next->data)
		sa(&head_a);
}

// int main(int argc, char *argv[]){
// 	t_node	*head_a = initialize_stack();
// 	t_node	*head_b = initialize_stack();

// 	// argv[argc] = NULL;

// 	// printf("-----");
// 	int i = 1;
// 	while (argv[i] != NULL)
// 	{
// 		int num = atoi(argv[i]);
// 		add_node(&head_a, num);
// 		i++;
// 	}

// 	print_list(&head_a);
// 	handle_three_nodes(head_a);
// 	print_list(&head_a);
// 	// printf("-----");
// 	// t_node *max_node = find_max_node(head_a);
// 	// printf("max: %d\n", max_node->data);

// 	// t_node	*last_node = find_last_node(head_a);
// 	// printf("last: %d\n", last_node->data);

// 	// int count = count_stack_length(head_a);
// 	// printf("count: %d\n", count);

// 	// printf("-----");
// }