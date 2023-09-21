#include "get_next_line.h"

/**
 * ft_strlen - Calculate the length of a null-terminated string.
 * @s: The null-terminated string to be measured.
 * Return: The length of the string 's'.
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
