
int find_cheapest_num(t_node **head_a, t_node **head_b, int indx)
{

	// 言い換えるとstack bからtarget_nodeを見つける作業
	// a_nodeと一番近くてより小さいtargetを見つける (a_node > b_node)
	// もし見つからなかったら、targetはmax_b_node (a_node < all_b_nodes)

	int	forward_count = 1;
	int back_count = 1;

	t_node *current_a = go_x_steps(&(*head_a), indx);
	t_node *current_b = (*head_b)->next;

	while (1)
	{
		// ターゲットが最小値の場合
		if (current_b->data <= current_b->next->data && current_a->data < current_b->data)
			break ;
		// max 谷を見つける
		if (current_b->data <= current_b->next->data && current_a->data > current_b->data)
			break ;
		// ハマるところを見つける
		if (current_a->data < current_b->data && current_a->data >= current_b->next->data)
			break ;
		current_b = current_b->next;
		forward_count++;
	}
	current_b = (*head_b)->prev;

	while (1)
	{
		// ターゲットが最小値の場合
		if (current_b->prev->data <= current_b->data && current_a->data < current_b->data)
			break ;
		// max 谷を見つける
		if (current_b->prev->data <= current_b->data && current_a->data > current_b->data)
			break ;
		// ハマるところを見つける
		if (current_a->data > current_b->data && current_a->data <= current_b->prev->data)
			break ;
		current_b = current_b->prev;
		back_count++;
	}
	printf("forward: %d\n", forward_count);
	printf("backword: %d\n", back_count);
	if (forward_count < back_count)
		return (forward_count + indx);
	return (-(back_count + indx));
}

t_node *check_stack_a(t_node **head_a, t_node **head_b)
{
	int i = 0;
	// t_operations *operation;
	// operation = malloc(sizeof(t_operations));
	// operation->rotation = 1;
	int	current_count;
	int min_count = INT_MAX;
	while (i < 4)
	{
		// operation->push_cost = 0;
		current_count = find_cheapest_num(&(*head_a), &(*head_b), i);
		if (current_count < 0)
		{
			// operation->rotation = -1;
			current_count *= -1;
		}
		// current_count += i;
		printf("current_count: %d\n\n", current_count);
		if (current_count < min_count)
		{
			min_count = current_count;
			// operation->a_indx = i;
		}
		printf("min_count: %d\n\n", min_count);

		i++;
	}
	// operation->push_cost = min_count;
	return (*head_a);
}
