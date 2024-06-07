#include "node.h"
#include "libft/libft.h"

void three_optical(t_node *head_a)
{
	int *first = &head_a->next->data;
	int *second = &head_a->next->next->data;
	int *third = &head_a->next->next->next->data;

	// 1 3 2 -> sa, ra
	if (*first <= *second && *third <= *second && *first <= *third)
	{
		sa(head_a);
		ra(head_a);
	}
	// 2 1 3 -> sa
	else if (*first >= *second && *third >= *second && *first <= *third)
	{
		sa(head_a);
	}
	// 2 3 1 -> rra
	else if (*first <= *second && *third <= *second && *first >= *third)
	{
		rra(head_a);
	}
	// 3 1 2 -> ra
	else if (*first >= *second && *third > *second && *first > *third)
	{
		ra(head_a);
	}
	// 3 2 1 -> sa, rra
	else if (*first >= *second && *third <= *second && *first >= *third)
	{
		sa(head_a);
		rra(head_a);
	}
	else
		return;
}
