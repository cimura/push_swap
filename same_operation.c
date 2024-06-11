#include "node.h"

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	ft_putstr_fd("rrr\n", 1);

}