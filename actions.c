#include "monty.h"

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
