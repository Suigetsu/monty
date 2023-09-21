#include "get_next_line.h"

/**
 * readnsave - Reads and appends data from a file descriptor into a buffer.
 * @fd: The file descriptor to read data from.
 * @holder: A pointer to a string that holds accumulated data.
 * Return: A pointer to the modified 'holder' string if successful, or NULL
 * on failure.
 */

char	*readnsave(int fd, char *holder)
{
	char	*buff;
	int		count;

	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free (holder);
			free (buff);
			return (NULL);
		}
		buff[count] = '\0';
		holder = gnljoin(holder, buff);
		if (ft_isnewline(holder))
			break ;
	}
	free (buff);
	return (holder);
}

/**
 * readline - Extracts a single line from a buffer.
 * @buff: A pointer to a null-terminated string containing data.
 * Return: A pointer to the extracted line including the newline character, or
 * NULL on failure or if 'buff' is empty.
 */

char	*readline(char *buff)
{
	char	*line;
	int		index;

	index = 0;
	if (buff[index] == '\0')
		return (NULL);
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
	{
		line = gnlsubstr(buff, 0, (index + 2));
		line[index] = '\n';
		line[index + 1] = '\0';
	}
	else
	{
		line = gnlsubstr(buff, 0, (index + 1));
		line[index] = '\0';
	}
	return (line);
}

/**
 * newline - Removes and returns everything before the first newline character.
 * @buff: A pointer to a null-terminated string containing data.
 * Return: A pointer to the remaining data after the first newline character,
 * or NULL if 'buff' is empty or does not contain a newline character.
 */

char	*newline(char *buff)
{
	char	*newholder;
	int		index;

	index = 0;
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\0')
	{
		free (buff);
		return (NULL);
	}
	newholder = gnlsubstr(buff, (index + 1), (ft_strlen(buff) - index + 1));
	free (buff);
	return (newholder);
}

/**
 * get_next_line - Reads and returns the next line from a file descriptor.
 * @fd: The file descriptor to read data from.
 * Return: A pointer to the next line read from 'fd', or NULL if there are no
 * more lines to read or if an error occurs.
 */

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = readnsave(fd, holder);
	if (buff == NULL)
	{
		free(buff);
		holder = NULL;
		return (NULL);
	}
	line = readline(buff);
	holder = newline(buff);
	return (line);
}
