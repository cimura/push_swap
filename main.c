/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:47:49 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/09 15:29:23 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft/libft.h"
#include "node.h"

int main(int argc, char *argv[])
{
	t_node	*head_a = initialize_stack();
	t_node	*head_b = initialize_stack();
	t_operations *operation;
	operation = malloc(sizeof(t_operations));

	argv[argc] = NULL;

	int i = 1;
	while (argv[i] != NULL)
	{
		int num = atoi(argv[i]);
		add_node(&head_a, num);
		i++;
	}

	printf("-- a ---\n");
	print_list(&head_a);
	printf("---b--\n");
	print_list(&head_b);

	printf("... optical....\n\n");

	int count = calculate_push_cost(head_a, head_a->next->next->next, operation);

	// printf("ope,rotation-> %d\n", operation->rotation);
	// printf("count %d\n", count);

	i = 0;
	while (i < count)
	{
		if (operation->rotation == 1)
			ra(&head_a);
		else
			rra(&head_a);
		i++;
	}
	rra(&head_a);
	ra(&head_a);
	printf("-- a ---\n");
	print_list(&head_a);
	printf("---b--\n");
	print_list(&head_b);

	// pb(&head_a, &head_b);
	// pb(&head_a, &head_b);
	// pb(&head_a, &head_b);

	// printf("-- a ---\n");
	// print_list(&head_a);
	// printf("---b--\n");
	// print_list(&head_b);

	// printf("\n\n");

	// rrb(&head_b);

	// printf("-- a ---\n");
	// print_list(&head_a);
	// printf("---b--\n");
	// print_list(&head_b);

	// printf("\n\n");

}