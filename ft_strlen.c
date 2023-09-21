#include "get_next_line.h"

/**
 * ft_putstr_fd - Writes a string to a file descriptor.
 *
 * @s: The string to be written.
 * @fd: The file descriptor to which the string is written.
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
