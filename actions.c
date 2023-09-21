#include "monty.h"

void	push(sstack_t **stack, int data)
{
    sstack_t *new_node;
	
	new_node = create_node(data);
    if (*stack != NULL)
	{
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void	pall(sstack_t *stack)
{
    sstack_t *current;
	current = stack;
    while (current != NULL)
	{
        printf("%d\n", current->n);
        current = current->next;
    }
}
