#include "node.h"

// functions to handle errors

int	count_stack_length(t_node *head)
{
	t_node	*current = head->next;
	int count = 0;
	while (current != head)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_node	*find_last_node(t_node *head)
{
	t_node	*current = head;
	current = current->prev;
	return (current);
}

t_node	*find_max_node(t_node *head)
{
	t_node	*current = head->next;
	t_node	*max_node = current;
	while (current != head)
	{
		if (max_node->data < current->data)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_node *head)
{
	t_node	*current = head->next;
	t_node	*min_node = current;
	while (current != head)
	{
		if (min_node->data > current->data)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}