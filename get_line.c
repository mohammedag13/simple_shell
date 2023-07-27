#include "shell.h"

/**
 * get - copies the string into the buffer.
 * @buf: the string.
 * @lineptr: array of strings.
 * @n: the buffer size.
 * @buf_s: buffer size.
 * @stream: the file.
 * Return: the count.
 */

size_t get(char *buf, char **lineptr, size_t *n, size_t buf_s, FILE *stream)
{
	ssize_t length = 0, new_size;
	int c;
	char *new_buffer;

	while ((c = fgetc(stream)) != EOF)
	{
	if (length >= (ssize_t) buf_s - 1)
	{
	new_size = buf_s * GROWTH_FACTOR;
	new_buffer = (char *)realloc(buf, new_size * sizeof(char));

	if (new_buffer == NULL)
	return (-1);

	buf = new_buffer;
	buf_s = new_size;
	*lineptr = buf;
	*n = buf_s;
	}

	buf[length++] = (char)c;
	if (c == '\n')
	break;
	}
	if (length == 0)
	return (-1);

	buf[length] = '\0';
	return (length);
}


/**
 * _getline - custom get_line function
 * @lineptr: pointer to line string
 * @n: size
 * @stream: steam file
 * Return: number of readed character
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer;
	size_t buffer_size;
	ssize_t len;

	if (lineptr == NULL || n == NULL || stream == NULL)
	return (-1);

	if (*lineptr == NULL || *n < INITIAL_BUFFER_SIZE)
	{
	*lineptr = (char *)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
	*n = INITIAL_BUFFER_SIZE;
	}


	buffer = *lineptr;
	buffer_size = *n;

	len = get(buffer, lineptr, n, buffer_size, stream);
	return (len);
}
