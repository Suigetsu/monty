#ifndef MONTY_H
# define MONTY_H

# define ERROR -1
# define PUSH_ERROR -2
# define PALL 0
# define PUSH 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"

/**
 * struct s_stack - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct  s_stack
{
	int				n;
	struct s_stack	*prev;
	struct s_stack	*next;
}               t_stack;

/**
 * struct general_s - a struct for general variables
 * @fd: file descriptor
 * @nbr: integer
 * @line: line we read from a file
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct	general_s
{
	int		fd;
	int		nbr;
	char	*line;
}				general_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * @general: a struct for the general vars
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct	instruction_s
{
	char		*opcode;
	void		(*f)(t_stack **stack, unsigned int line_number);
	general_t	general;
}		instruction_t;

/******************************************************/
/*                 error handling                     */
/******************************************************/

int		is_file_valid(char *filename);
int		check_file_open(char *filename, instruction_t *instr);

/******************************************************/
/*                read from the file                  */
/******************************************************/

int			parse_file_args(char *filename, instruction_t *var, t_stack **stack);
int			check_action(char *line, instruction_t *var);

/******************************************************/
/*                linked list functions               */
/******************************************************/

t_stack		*create_node(int data);
void		insert_at_end(t_stack **head, int data);
void		free_linkedlist(t_stack **head);

/******************************************************/
/*                      actions                       */
/******************************************************/

void	push(t_stack **stack, int data);
void	pall(t_stack *stack);

#endif
