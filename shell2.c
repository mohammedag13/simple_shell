#include "shell.h"

/**
 * execute_commandV - Fork and execute the command.
 * @m: The string that should be executed.
 * Return: always 0.
 */

int execute_commandV(memory *m)
{
	pid_t child_id = -1;
	int command_status = 0;

	m->agv = arr_of_tokens(m->command, " \t\r\n\a");
	if (m->agv == NULL)
		return (0);
	handle_args(m), command_status = check_command_exit(m->agv);
	if (command_status == -1)
	{
		fprintf(stderr, "%s: ", m->program_args[0]);
		fprintf(stderr, "%d: %s: ", m->command_number, m->agv[0]);
		fprintf(stderr, "not found\n"), free_array_of_strings(m->agv);
		m->last_exit_code = 127;
		return (-1);
	}
	if (command_status != 3)
	{
		child_id = fork();
		if (child_id == 0)
		{
			execve(m->agv[0], m->agv, m->env);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		else
		{
			wait(&(m->current_status_code));
			if (WIFEXITED(m->current_status_code))
			{
				m->current_status_code = WEXITSTATUS(m->current_status_code);
				m->last_exit_code = m->current_status_code;
			}
		}
	}
	else
		handle_built_in(m);
	free_array_of_strings(m->agv);
	return (0);
}

/**
 * handle_built_in - handles the argguments.
 * @m: the string.
 *
 * Return: description.
 */

int handle_built_in(memory *m)
{
	int i = 0;
	built_in h[] = {
	{"exit", handle_exit},
	{"cd", NULL},
	{"env",  handle_env},
	{NULL, NULL}
	};
	while (h[i].command)
	{
		if (_strcmp(h[i].command, m->agv[0]) == 0)
		{
			h[i].handler(m);
			return (1);
		}
	i++;
	}

	return (0);
}

/**
 * handle_args - handles the argguments.
 * @m: the string.
 *
 * Return: description.
 */

int handle_args(memory *m)
{
	int i = 0;
	int j = 0;

	ArgsHandler h[] = {
	{"#",  handle_hash},
	{"$$", handle_double_dollar},
	{"$?", handle_double_mark},
	{NULL, NULL}
	};

	while ((h + i)->name)
	{
	while (m->agv[j])
	{
	if (m->agv[j][0] == '#' && (h + i)->name[0] == '#')
	{
	(h + i)->handler(m, j);
	}
	else if (_strcmp((h + i)->name, m->agv[j]) == 0)
	{
	(h + i)->handler(m, j);
	}
	j++;
	}
	j = 0;
	i++;
	}
	return (0);
}
