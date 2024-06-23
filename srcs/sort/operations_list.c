/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:13 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/23 12:37:53 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

t_node	*create_node(long data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*initialize_stack(void)
{
	t_node	*head;

	head = create_node(0);
	head->next = head;
	head->prev = head;
	return (head);
}

void	add_node(t_node **head, long data)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(data);
	last = (*head)->prev;
	new_node->next = (*head);
	new_node->prev = last;
	last->next = new_node;
	(*head)->prev = new_node;
}

void	free_node(t_node *head)
{
	t_node	*current;
	t_node	*tmp;

	current = head->next;
	while (current != head)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(head);
}
