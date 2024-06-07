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
	pb(head_a, head_b);
	pb(head_a, head_b);
	pb(head_a, head_b);

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);
	
	printf("\n\n");

	// t_node *now = go_x_steps(head_a, 2);
	// printf("expected 34 -> %d\n", now->data);

	// aのスタックを見てbにpushするものを決める
	int indx = 1;
	printf("indx-> %d\n", indx);
	int cheapest_num = find_cheapest_num(head_a, head_b, indx);
	
	t_node *now_seeing = go_x_steps(head_a, indx);
	printf("\nnode->data: %d\n",now_seeing->data);

	printf("cheapest num: %d\n\n", cheapest_num);

	return (0);
}