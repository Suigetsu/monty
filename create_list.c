#include "monty.h"

sstack_t	*create_node(int data)
{
	sstack_t	*new_node;
	
	new_node = (sstack_t*)malloc(sizeof(sstack_t));
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

void	insert_at_end(sstack_t **head, int data)
{
	sstack_t *new_node;
	sstack_t *temp;

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

void	free_linkedlist(sstack_t **head)
{
	sstack_t *current;
	sstack_t *next_node;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		if (current)
			free(current);
		current = next_node;
	}
}
