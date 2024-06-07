/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:47:49 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/07 16:09:16 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft/libft.h"

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

	// if (count_list_nodes(head_a) == 3)
	// if (argc == 4)
	// {
	// 	printf("\e[32mSUCCESS!!\e[0m\n");
	// }

	pb(head_a, head_b);
	pb(head_a, head_b);

	// aのスタックを見てbにpushするものを決める
	int cheapest_num = check_stack_a(head_a, head_b);

	printf("... optical....\n\n");

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);	

	return (0);
}