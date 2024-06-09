#include "node.h"

int	calculate_push_cost(t_node *head, t_node *pos, t_operations *operation)
{
	int		count = 0;
	int		lstsize = count_stack_length(head);

	t_node	*current;

	current = pos;
	while (current != head)
	{
		current = current->next;
		count++;
	}
	if (count > lstsize / 2)
	{
		operation->rotation = 1;
		return (lstsize - count);
	}
	operation->rotation = -1;
	return (count);
}