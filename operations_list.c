/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:13 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/07 15:46:19 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*initialize_stack()
{
	t_node	*head = create_node(0);
	head->next = head;
	head->prev = head;
	return (head);
}

void	add_node(t_node *head, int data)
{
	t_node	*new_node = create_node(data);
	t_node	*last = head->prev;

	new_node->next = head;
	new_node->prev = last;
	last->next = new_node;
	head->prev = new_node;
}

void	print_list(t_node *head)
{
	t_node	*current = head->next;
	while (current != head)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int	count_list_nodes(t_node *head)
{
	t_node	*current = head;
	int count = 0;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_node	*go_x_steps(t_node *head, int num)
{
	t_node *current = head->next;
	int i = 0;
	while (current != NULL && i < num)
	{
		current = current->next;
		i++;
	}
	return (current);
}