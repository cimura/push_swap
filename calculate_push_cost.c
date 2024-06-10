#include "node.h"

int	calculate_push_cost(t_node *head, t_node *pos, int rewrite_enabled)
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
		if (rewrite_enabled == 1)
			head->rotation = 1;
		// head->to_push = lstsize - count;
		return (lstsize - count);
	}
	// head->to_push = count;
	if (rewrite_enabled == 1)
		head->rotation = -1;
	return (count);
}