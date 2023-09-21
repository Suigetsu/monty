#include "monty.h"

/**
 * is_file_valid - Checks if a file name ends with ".m".
 * @filename: A pointer to a null-terminated string representing the filename.
 * This function determines whether the given filename
 * ends with ".m" (case-sensitive).
 * Return: 1 if the filename ends with ".m", otherwise 0.
 */

int is_file_valid(char *filename)
{
	if (strncmp(&filename[strlen(filename) - 2], ".m", 3))
		return (1);
	return (0);
}

/**
 * check_file_open - Attempts to open a file and closes it immediately.
 * @filename: A pointer to a null-terminated string representing the filename.
 * @instr: A pointer to an instruction structure.
 * Return: 1 if the file cannot be opened, otherwise 0.
 */

int	check_file_open(char *filename, instruction_t *instr)
{
	instr->general.fd = open(filename, O_RDONLY);
	if (instr->general.fd < 0)
		return (1);
	close(instr->general.fd);
	return (0);
}
/**
 * failed_malloc - a function that prints an error message
 * and exits if malloc is failed
*/

void	failed_malloc(void)
{
	ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	my_atoi(char *str, instruction_t *var)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i - 1] == '-')
		sign *= -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		var->general.err_flag = -1;
		return (var->general.err_flag);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res *= sign;
	if (str[i] && str[i] != ' ' && str[i] != '\n')
	{
		var->general.err_flag = -1;
		return (var->general.err_flag);
	}
	return (res);
}
