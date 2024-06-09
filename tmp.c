#include "node.h"

int main(int argc, char *argv[])
{
	t_node	*head_a = initialize_stack();
	t_node	*head_b = initialize_stack();

	int i = 1;
	while (argv[i] != NULL)
	{
		int num = atoi(argv[i]);
		add_node(&head_a, num);
		i++;
	}

	printf("-- a ---\n");
	print_list(&head_a);
	printf("---b--\n");
	print_list(&head_b);

	printf("... optical....\n\n");

	pb(&head_a, &head_b);
	pb(&head_a, &head_b);

	printf("-- a ---\n");
	print_list(&head_a);
	printf("---b--\n");
	print_list(&head_b);

	printf("\n\n");

	t_operations *operations = check_stack_a(&head_a, &head_b);
	

	printf("cheapest num __count__: %d\n\n", operations->b_count);
	printf("cheapest num __rotation__: %d\n\n", operations->b_rotation);
	printf("cheapest num __a_indx__: %d\n\n", operations->a_indx);

	i = 0;
	while (i < operations->b_count)
	{
		if (count_stack_length(head_b) == 2)
			sb(&head_b);
		if (operations->b_rotation > 0 && !(count_stack_length(head_b) == 2))
			rb(&head_b);
		else if (operations->b_rotation <= 0 && !(count_stack_length(head_b) == 2))
			rrb(&head_b);
		i++;
	}
	pb(&head_a, &head_b);

	printf("\x1b[32m");

	printf("-- a ---\n");
	print_list(&head_a);
	printf("---b--\n");
	print_list(&head_b);

	printf("\x1b[m");
	return (0);
}