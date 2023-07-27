#include "shell.h"

memory initializeMemory(void)
{
	memory mem;

	mem.command = NULL;
	mem.agv = NULL;
	mem.command_number = 0;
	mem.current_status_code = 0;
	mem.program_args = NULL;
	mem.builtIn = NULL;
	mem.current_process_id = getppid();
	mem.last_exit_code = 0;
	mem.command_count = 0;

	return (mem);
}


/**
 * sigintHandler - control the (ctrl+c).
 * @signal: checks the return value.
 * Return: void.
 */
void sigintHandler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n$ ", 4);
	}
}

/**
 * check_command_exit - checks the command.
 * @args: the command.
 *
 * Return: -1.
 */

int check_command_exit(char **args)
{
	char *p1, *full_path;
	char *paths, **paths_del, **paths_free_p;

	if (check_built_ins(args) == 1)
		return (3);

	if (access(args[0], X_OK) == 0)
		return (1);

	paths = _getenv("PATH");
	paths_del = arr_of_tokens(paths, ":");
	paths_free_p = paths_del;

	while (*paths_del)
	{
		p1 = concatenate_string(*paths_del, "/");
		full_path = concatenate_string(p1, args[0]);

		if (access(full_path, X_OK) == 0)
		{
			free(args[0]);
			args[0] = full_path;
			free(paths);
			free(p1);
			free_array_of_strings(paths_free_p);
			return (2);
		}

		free(p1);
		free(full_path);

		paths_del++;
	}
	free(paths);
	free_array_of_strings(paths_free_p);

	return (-1);
}

/**
 * check_built_ins - checks the built_in commands.
 * @args: the commands.
 * Return: 1 or -1.
 */

int check_built_ins(char **args)
{
	char *build_in[] = {"exit", "env", "cd", "setenv", "unsetenv", NULL};
	int i = 0;

	while (build_in[i] != NULL)
	{
		if (_strcmp(build_in[i], args[0]) == 0)
			return (1);
		i++;
	}

	return (-1);
}

/**
 * main - checks the code.
 * @argc: the numbers of the argv.
 * @argv: the strings entered to the file.
 * @e: controls the environment.
 * Return: always 0.
 */





int main(int argc, char **argv, char **e)
{
		size_t num = 0;
	size_t len;

	memory m = initializeMemory();

	m.program_args = argv;
	m.program_arg_count = argc;
	m.env = e;

	signal(SIGINT, sigintHandler);

	if (isatty(STDIN_FILENO) && argc == 1)
		write_charV(1, "$ ", 2);

	while (_getline(&m.command, &num, stdin) != EOF)
	{
		len = _strlen(m.command);
		m.command_number++;

		if (len != 1 && m.command[0] != '#')
		{
			m.command[len - 1] = '\0';
			execute_multi_command(&m);
		}
		if (isatty(STDIN_FILENO) && argc == 1)
			write_charV(1, "$ ", 2);
	}

	free(m.command);
	return (0);
}


