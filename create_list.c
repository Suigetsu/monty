#include "monty.h"

t_stack	*create_node(int data)
{
	t_stack	*new_node;
	
	new_node = (t_stack*)malloc(sizeof(t_stack));
	if (!new_node)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	insert_at_end(t_stack **head, int data)
{
	t_stack *new_node;
	t_stack *temp;

	new_node = create_node(data);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	free_linkedlist(t_stack **head)
{
	t_stack *current;
	t_stack *next_node;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		if (current)
			free(current);
		current = next_node;
	}
}
