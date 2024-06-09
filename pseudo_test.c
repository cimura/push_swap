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

	add_node(&head_b, 1);
	add_node(&head_b, 7);
	add_node(&head_b, 5);
	add_node(&head_b, 2);

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

	t_node *target = find_target(head_a->next, head_b);
	printf("target->data\t->\t%d\n", target->data);
	int count = calculate_push_cost(head_b, target);
	printf("count\t\t->\t%d\n", count);
	printf("rotation\t->\t%d\n", head_b->rotation);
}