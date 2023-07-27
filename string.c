#include "shell.h"

/**
 * write_charV - returns a written string.
 * @fd: the number of lines.
 * @buffer: the string.
 * @size: the number of characters.
 * Return: a string..
 */

int write_charV(int fd, const char *buffer, size_t size)
{
	return (write(fd, buffer, size));
}

/**
 * free_array_of_strings - free the array of string.
 * @a: the string should be freed.
 * Return: the string.
 */

void free_array_of_strings(char **a)
{
	char **t = a;

	while (*a)
	{
		free(*a);
		a++;
	}
	free(t);
}

/**
 * concatenate_string - concatinate 2 strings.
 * @s1: the first string.
 * @s2: the second string.
 * Return: a string.
 */

char *concatenate_string(char *s1, char *s2)
{
	char *con = NULL;
	int len_1 = 0, len_2 = 0, i = 0, j = 0;
	int full_length;

	while (s1[len_1])
	{
		len_1++;
	}

	while (s2[len_2])
	{
		len_2++;
	}

	full_length = len_1 + len_2 + 1;
	con = malloc(sizeof(char) * full_length);

	while (i < len_1)
	{
		con[i] = s1[i];
		i++;
	}
	while (j < len_2)
	{
		con[i] = s2[j];
		j++;
		i++;
	}
	con[i] = '\0';

	return (con);
}
