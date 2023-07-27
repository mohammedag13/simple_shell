#include "shell.h"

/**
 * handle_exit - handles exit command.
 * @m: a struct.
 * Return: void.
 */

void handle_exit(struct memory *m)
{
	int n = 0;

	if (m->agv[1])
	{
		n = _atoi_with_error(m->agv[1]);
		if (n == -1)
		{
			m->last_exit_code = 2;
			fprintf(stderr, "%s: ", m->program_args[0]);
			fprintf(stderr, "%d: %s: ", m->command_number, m->agv[0]);
			fprintf(stderr, "Illegal number: %s\n", m->agv[1]);
		}
		else
		{
			m->last_exit_code = n;
		}
	}

	free(m->current_command);
	free_array_of_strings(m->commands);
	free_array_of_strings(m->agv);
	exit(m->last_exit_code);
}

/**
 * handle_env - handles the environments.
 * @m: a struct.
 * Return: void.
 */

void handle_env(struct memory *m)
{
	char **env;

	(void)m;
	env = environ;
	while (*env)
	{
		puts(*env);
		env++;
	}

}
