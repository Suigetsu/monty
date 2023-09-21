#include "monty.h"

/**
 * push - Pushes a new node with data onto the top of a stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @data: The integer data to be added to the new node.
*/

void	push(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = create_node(data);
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - Prints all the elements of a stack.
 *
 * @stack: A pointer to the top node of the stack to be printed.
*/

void	pall(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
