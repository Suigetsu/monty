#include "get_next_line.h"

/**
 * ft_putstr_fd - Writes a string to a file descriptor.
 * @s: The string to be written.
 * @fd: The file descriptor to which the string is written.
 */

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
