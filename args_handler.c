#include "shell.h"

/**
 * handle_hash - handle the hash for non interactive mode.
 * @m: a struct.
 * @i: the index.
 * Return: void.
 */

void handle_hash(struct memory *m, int i)
{
	free(m->agv[i]);
	m->agv[i] = NULL;
	i++;

	while (m->agv[i])
	{
		free(m->agv[i]);
		m->agv[i] = NULL;
		i++;
	}
}

/**
 * handle_double_dollar - handles the double dollar sign.
 * @m: a struct.
 * @i: the index.
 * Return: void.
 */

void handle_double_dollar(struct memory *m, int i)
{
	char *s;

	free(m->agv[i]);
	s = malloc(sizeof(char) * 256);
	int_to_string(m->current_process_id, s);
	m->agv[i] = s;
}
/**
 * handle_double_mark - handles the double mark.
 * @m: a struct.
 * @i: the index.
 * Return: void.
 */

void handle_double_mark(struct memory *m, int i)
{
	char *s;

	free(m->agv[i]);
	s = malloc(sizeof(char) * 256);
	int_to_string(m->last_exit_code, s);
	m->agv[i] = s;
}
