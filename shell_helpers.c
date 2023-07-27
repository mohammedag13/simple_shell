#include "shell.h"

/**
 * count_of_tok - counts the number of tokens.
 * @command: the string that should be divided into tokens.
 * @del: the separator for the token.
 * Return: the number of tokens.
 */

int count_of_tok(char *command, char *del)
{
	char *command_cpy = NULL;
	char *token;
	size_t cnt = 0;
	int m = 0, n = 0;

	while (command[n])
	{
	n++;
	}

	cnt = n + 1;
	command_cpy = malloc(sizeof(char) * cnt);
	_strcpy(command_cpy, command);
	token = strtok(command_cpy, del);
	while (token)
	{
	m++;
	token = strtok(NULL, del);
	}

	free(command_cpy);
	return (m);
}

/**
 * arr_of_tokens - copies the tokens into array of strings.
 * @command: the string should be divided into tokens.
 * @del: the separator.
 * Return: the array of strings..
 */

char **arr_of_tokens(char *command, char *del)
{
	char *token;
	size_t count = 0;
	char *command_cpy = NULL;
	char **arr_str;
	int i = 0;
	char *temp;

	count = _strlen(command) + 1;
	command_cpy = malloc(sizeof(char) * count);
	_strcpy(command_cpy, command);

	arr_str = malloc(sizeof(char *) * (count_of_tok(command, del) + 1));

	token = strtok(command_cpy, del);
	while (token)
	{
		temp = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(temp, token);
		arr_str[i] = temp;
		token = strtok(NULL, del);
		i++;
	}
	if (i == 0)
	{
		free(arr_str);
		free(command_cpy);
		return (NULL);
	}

	arr_str[i] = NULL;
	free(command_cpy);
	return (arr_str);
}

/**
 * string_array_cp - copies the array of string.
 * @des: the string should be copied to.
 * @src: the string should be copied from.
 * Return: void.
 */

void string_array_cp(char ***des, char **src)
{
	size_t cnt = 0;
	char **temp = src;
	size_t sub_string_len = 0, num = 0;
	int i = 0;

	while (*temp++)
	cnt++;

	cnt++;
	(*des) = malloc(sizeof(char *) * cnt);

	temp = src;
	while (*temp)
	{
	num = _strlen(*temp);
	sub_string_len = num + 1;
	(*des)[i] = malloc(sizeof(char) * sub_string_len);
	_strcpy((*des)[i], *temp);
	i++;
	temp++;
	}

	(*des)[i] = NULL;
}

/**
 * int_to_string - converts int to string.
 * @number: the number.
 * @str: the string.
 * Return: void.
 */

void int_to_string(int number, char *str)
{
	int i = 0;
	int j = 0;
	int isNegative = 0;
	int length;
	char temp;

	if (number < 0)
	{
		isNegative = 1;
		number = -number;
	}

	do {
		str[i++] = number % 10 + '0';
		number /= 10;
	} while (number > 0);

	if (isNegative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	length = i;
	for (j = 0; j < length / 2; j++)
	{
		temp = str[j];
		str[j] = str[length - j - 1];
		str[length - j - 1] = temp;
	}
}
