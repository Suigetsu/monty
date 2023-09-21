#include "monty.h"

int	main(int ac, char **av)
{
	t_stack		*stack;
	instruction_t	instr;

	stack = NULL;
	bzero(&instr, sizeof(instruction_t));
	if (ac != 2 || is_file_valid(av[1]))
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}
	if (check_file_open(av[1], &instr))
	{
		write(STDERR_FILENO, "Error: Can't open file\n", 24);
		exit(EXIT_FAILURE);
	}
	parse_file_args(av[1], &instr, &stack);
	free_linkedlist(&stack);
	return (0);
}
