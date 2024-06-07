#include "node.h"

int main(int argc, char *argv[])
{
	t_node	*head_a = initialize_stack();
	t_node	*head_b = initialize_stack();

	argv[argc] = NULL;

	int i = 1;
	while (argv[i] != NULL)
	{
		int num = atoi(argv[i]);
		add_node(head_a, num);
		i++;
	}

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);

	printf("... optical....\n\n");

	// if (count_list_nodes(head_a) == 3)
	// if (argc == 4)
	// {
	// 	printf("\e[32mSUCCESS!!\e[0m\n");
	// }

	pb(head_a, head_b);
	pb(head_a, head_b);
	// pb(head_a, head_b);
	// pb(head_a, head_b);
	// pb(head_a, head_b);

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);

	printf("\n\n");

	// t_node *now = go_x_steps(head_a, 2);
	// printf("expected 34 -> %d\n", now->data);

	// aのスタックを見てbにpushするものを決める
	// int indx = 1;
	// printf("indx-> %d\n", indx);
	t_operations *operations = check_stack_a(head_a, head_b);
	
	// t_node *now_seeing = go_x_steps(head_a, indx);
	// printf("\nnode->data: %d\n",now_seeing->data);

	printf("cheapest num __count__: %d\n\n", operations->b_count);
	printf("cheapest num __rotation__: %d\n\n", operations->b_rotation);
	printf("cheapest num __a_indx__: %d\n\n", operations->a_indx);

	i = 0;
	while (i < operations->b_count)
	{
		if (operations->b_rotation > 0)
			rb(head_b);
		else
			rrb(head_b);
		i++;
	}
	pb(head_a, head_b);

	printf("\x1b[32m");

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);

	printf("\x1b[m");

	// if (cheapest_num > 0)
	// {
	// 	int i = 0;
	// 	while (i < cheapest_num)
	// 	{

	// 		i++;
	// 	}
	// }
	// else
	// {
	// 	cheapest_num -= 1;
	// 	int i = 0;
	// 	while (i < cheapest_num)
	// 	{
			
	// 		i++;
	// 	}
	// }
	// printf("-- a ---\n");
	// print_list(head_a);
	// printf("---b--\n");
	// print_list(head_b);

	return (0);
}