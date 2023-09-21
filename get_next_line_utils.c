#include "get_next_line.h"

/**
 * ft_isnewline - Checks if a string contains a newline character.
 * @s: A pointer to a null-terminated string to be checked.
 * Return: 1 if 's' contains a newline character, 0 otherwise.
 */

int	ft_isnewline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/**
 * gnljoin - Concatenates two strings.
 * @s1: The first null-terminated string.
 * @s2: The second null-terminated string to be appended to s1.
 * Return: A pointer to the concatenated string, or NULL on failure.
 */

char	*gnljoin(char *s1, char *s2)
{
	char	*cat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\0')
		cat[i++] = s2[j++];
	cat[i] = '\0';
	return (cat);
}

/**
 * gnlsubstr - Extracts a substring from a given string.
 * @s: The null-terminated string to extract a substring from.
 * @start: The starting index of the substring.
 * @len: The length of the substring to extract.
 * Return: A pointer to the extracted substring, an empty string, or NULL on failure.
 */

char	*gnlsubstr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc((len + 1) * sizeof(char));
	if (s == NULL || sub == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
