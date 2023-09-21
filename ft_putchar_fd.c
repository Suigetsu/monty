#include "get_next_line.h"

/**
 * ft_putchar_fd - Writes a character to a file descriptor.
 * @c: The character to be written.
 * @fd: The file descriptor to which the character is written.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
