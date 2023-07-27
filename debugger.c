#include "shell.h"

/**
 * print_string - print the string s.
 * @s: the string that should be printed.
 * Return: void.
 */

void print_string(char *s)
{
	char *t = s;

	while (*t)
	{
		write_charV(1, t, 1);
		t++;
	}
}

/**
 * print_array_of_strings - print array of string s.
 * @s: the array of string that should be printed.
 * Return: void.
 */

void print_array_of_strings(char **s)
{
	char **t = s;

	while (*t)
	{
	char *p = *t;

	while (*p)
	{
	write_charV(1, p, 1);
	p++;
	}
	write_charV(1, "\n", 1);
	t++;
	}
}

