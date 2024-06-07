/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:47:49 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/07 13:41:39 by sshimura         ###   ########.fr       */
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

	// add_node(head_b, 4);

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);	

	three_optical(head_a);
	// pb(head_a, head_b);
	printf("\n\n optical....\n\n");

	printf("-- a ---\n");
	print_list(head_a);
	printf("---b--\n");
	print_list(head_b);	

	return (0);
}