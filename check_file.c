#include "monty.h"

/**
 * check_action - Checks the validity of a given instruction line.
 * @line: The instruction line to be checked.
 * @var: A pointer to an instruction structure to store data.
 * Return:
 * - PUSH (1) if the instruction is valid and a "push" operation.
 * - PALL (0) if the instruction is valid and a "pall" operation.
 * - ERROR (-1) if the instruction is invalid or contains errors.
 */

int	check_action(char *line, instruction_t *var)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] != ' ')
		{
			if (!strncmp(&line[i], "\n", 2))
				break;
			if (strncmp(&line[i], "push ", 5) &&
			strncmp(&line[i], "pall ", 5) && strncmp(&line[i], "pall", 5))
			{
				var->opcode = strdup(&line[i]);
				return (ERROR);
			}
			if (!strncmp(&line[i], "push ", 5))
				break;
			return (PALL);
		}
	}
	while (line[i])
	{
		while (line[i] && line[i] != ' ')
			i++;
		if (line[i] == ' ')
			break;
	}
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] != ' ')
		{
			if (atoi(&line[i]) == 0)
				return (PUSH_ERROR);
			var->general.nbr = atoi(&line[i]);
			break;
		}
	}
	return (PUSH);
}

/**
 * parse_file_args - Parses instructions from a file and performs actions.
 * @filename: The name of the file containing instructions.
 * @var: A pointer to an instruction structure to store data.
 * @stack: A pointer to a stack structure to be manipulated.
 * Return:
 * - 0 on successful parsing and execution of instructions.
 * - ERROR (-1) if there is an error during parsing or execution.
 */

int	parse_file_args(char *filename, instruction_t *var, t_stack **stack)
{
	int	linecount;

	linecount = 1;
	var->general.fd = open(filename, O_RDONLY);
	var->general.line = get_next_line(var->general.fd);
	while (var->general.line)
	{
		if (check_action(var->general.line, var) == ERROR)
		{
			ft_putchar_fd('L', STDERR_FILENO);
			ft_putnbr_fd(linecount, STDERR_FILENO);
			ft_putstr_fd(": unknown instruction ", STDERR_FILENO);
			ft_putstr_fd(var->opcode, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			free(var->general.line);
			free(var->opcode);
			free_linkedlist(stack);
			close(var->general.fd);
			return (ERROR);
		}
		else if (check_action(var->general.line, var) == PUSH_ERROR)
		{
			ft_putchar_fd('L', STDERR_FILENO);
			ft_putnbr_fd(linecount, STDERR_FILENO);
			ft_putstr_fd(": usage: push integer\n", STDERR_FILENO);
			free(var->general.line);
			free_linkedlist(stack);
			close(var->general.fd);
			return (ERROR);
		}
		else if (check_action(var->general.line, var) == PUSH)
			push(stack, var->general.nbr);
		else if (check_action(var->general.line, var) == PALL)
			pall(*stack);
		free(var->general.line);
		var->general.line = get_next_line(var->general.fd);
		linecount++;
	}
	close(var->general.fd);
	return (0);
}
