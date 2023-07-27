#include "shell.h"

/**
 * _getenv - Divides the string into tokens.
 * @name: The string that should be divided.
 *
 * Return: value
 */

char *_getenv(char *name)
{
	int i = 0;
	char *del = "=";
	char *token;
	char **temp = NULL;
	size_t sub_string = 0;
	char *value = NULL;

	string_array_cp(&temp, environ);
	while (temp[i])
	{
		token = strtok(temp[i], del);
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, del);
			sub_string = _strlen(token) + 1;
			value = malloc(sizeof(char) * sub_string);
			_strcpy(value, token);
			break;
		}
		i++;
	}
	free_array_of_strings(temp);

	return (value);
}
