#ifndef MONTY_H
# define MONTY_H

# define ERROR -1
# define PALL 0
# define PUSH 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct  stack_s
{
	int				n;
	char			*action;
	struct stack_s	*prev;
	struct stack_s	*next;
}               sstack_t;


typedef struct	general_s
{
	int		fd;
	int		nbr;
	char	*line;
	char	*token;
}				general_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct	instruction_s
{
	char		*opcode;
	void		(*f)(stack_t **stack, unsigned int line_number);
	general_t	general;
}		instruction_t;

/******************************************************/
/*                 error handling                     */
/******************************************************/

int	is_file_valid(char *filename);
int	check_file_open(char *filename, instruction_t *instr);

/******************************************************/
/*                read from the file                  */
/******************************************************/

int			parse_file_args(char *filename, instruction_t *var, sstack_t **stack);
int			check_action(char *line, instruction_t *var);

/******************************************************/
/*                linked list functions               */
/******************************************************/

sstack_t	*create_node(int data);
void		insert_at_end(sstack_t **head, int data);
void		free_linkedlist(sstack_t **head);

/******************************************************/
/*                      actions                       */
/******************************************************/

void	push(sstack_t **stack, int data);
void	pall(sstack_t *stack);

#endif
