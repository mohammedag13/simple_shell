#include "shell.h"
/**/
/**
 * _strlen - measures the lenght of the string.
 * @s: the string that should be measured.
 * Return: the lenght of the string.
 */

size_t _strlen(char *s)
{
	size_t counter = 0;

	while (s[counter] != '\0')
	{
	counter++;
	}

	return (counter);
}

/**
 * _strcpy - copies the string from one pointer to another.
 *
 * @m: the string should be copied to.
 * @n: the string should be copied from.
 * Return: the new string.
 */

char *_strcpy(char *m, char *n)
{
	size_t i = 0;

	while (n[i])
	{
	m[i] = n[i];
	i++;
	}
	m[i] = '\0';

	return (m);
}

/**
 * _strcmp - compares any two strings
 * @s: the first string.
 * @x: the second string.
 * Return: 0 - 1.
 */
int _strcmp(char *s, char *x)
{
	int i = 0;
	int s_l = _strlen(s);
	int x_l = _strlen(x);

	if (s_l != x_l)
		return (-1);

	while (s[i] && x[i])
	{
		if (s[i] != x[i])
			return (-1);

		i++;
	}
	return (0);

}

/**
 * _strncpy_size - copy string.
 * @destination: the string will be copied to.
 * @source: the string should be copied from.
 * @num: the lenght of the string.
 * Return: a string.
 */

char *_strncpy_size(char *destination, const char *source, size_t num)
{
	size_t i;

	for (i = 0; i < num && source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	for (; i < num; i++)
	{
		destination[i] = '\0';
	}

	return (destination);
}

/**
 * _atoi_with_error - finding the errors value.
 * @s: the string.
 * Return: int or -1.
 */


int _atoi_with_error(char *s)
{
	int i = 0;
	unsigned long int number = 0;

	/* escape the +1000 +plus sign */
	if (*s == '+')
		s++;

	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			number *= 10;
			number += (s[i] - '0');
			if (number > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (number);

}
