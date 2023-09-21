#include "monty.h"

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
				return (ERROR);
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
				return (ERROR);
			var->general.nbr = atoi(&line[i]);
			break;
		}
	}
	return (PUSH);
}

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
