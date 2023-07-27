#include "shell.h"

/**
 * removeLeadingSpaces - remove the leading space.
 * @str: the string.
 * Return: void.
 */


void removeLeadingSpaces(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}

	while (str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}

	str[j] = '\0';
}

/**
 * execute_multi_command - execute the multi commands.
 * @m: a struct object.
 * Return: int.
 */


int execute_multi_command(memory *m)
{
	char **commands = arr_of_tokens(m->command, ";");
	char **s = commands;

	m->commands = commands;
	m->current_command = m->command;

	while (*s)
	{
		m->command_count++;
		s++;
	}
	s = commands;
	while (*s)
	{
		removeLeadingSpaces(*s);
		m->command = (*s);
		execute_commandV(m);
		s++;
	}
	m->command = m->current_command;
	free_array_of_strings(commands);

	return (0);

}
