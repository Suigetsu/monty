#include "monty.h"

int	is_file_valid(char *filename)
{
	if (strncmp(&filename[strlen(filename) - 2], ".m", 3))
		return (1);
	return (0);
}
int	check_file_open(char *filename, instruction_t *instr)
{
	instr->general.fd = open(filename, O_RDONLY);
	if (instr->general.fd < 0)
		return (1);
	close(instr->general.fd);
	return (0);
}
