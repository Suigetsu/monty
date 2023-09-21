#include "monty.h"

/**
 * create_node - Creates a new node for a stack with the given data.
 * @data: The integer data to be stored in the new node.
 * Return: A pointer to the newly created node.
 */

t_stack	*create_node(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		failed_malloc();
	new_node->n = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * insert_at_end - Inserts a new node with data at the end of a linked list.
 *
 * @head: A pointer to a pointer to the head node of the linked list.
 * @data: The integer data to be added to the new node.
 */

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

/**
 * free_linkedlist - Frees all nodes in a linked list.
 *
 * @head: A pointer to a pointer to the head node of the linked list.
*/

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
