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
