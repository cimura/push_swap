#include "../header/node.h"

int	calculate_push_cost(t_node *head, t_node *pos, bool overwrite_enabled)
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
		head->is_clockwise = true;
		if (overwrite_enabled == 1)
			head->rotation = 1;
		// head->to_push = lstsize - count;
		return (lstsize - count);
	}
	// head->to_push = count;
	if (overwrite_enabled == 1)
		head->rotation = -1;
	head->is_clockwise = false;
	return (count);
}