/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:46:13 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/12 14:49:52 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
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

void	add_node(t_node **head, int data)
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

void	print_list(t_node *head)
{
	t_node	*current;

	current = head->next;
	while (current != head)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

t_node	*go_x_steps(t_node **head, int num)
{
	int		i;
	t_node	*current;

	i = 0;
	current = (*head)->next;
	while (current != NULL && i < num)
	{
		current = current->next;
		i++;
	}
	return (current);
}