#include "shell.h"

/**
 * _memcpy - copies a block of memory from one place to another.
 * @destination: the place to be copied  to.
 * @source: the place to copy from.
 * @number_of_bytes: number of bytes.
 * Return: void.
 */

void _memcpy(void *destination, void *source, size_t number_of_bytes)
{
	size_t i;
	char *dest = (char *) destination;
	const char *src = (const char *) source;

	for (i = 0; i < number_of_bytes; ++i)
	{
		dest[i] = src[i];
	}
}

/**
 * _memset - fill a block of memory with a specific value.
 * @value: the value.
 * @num: number of bytes.
 * @ptr: the strings needs to be filled.
 * Return: a string.
 */

void *_memset(void *ptr, int value, size_t num)
{
	unsigned char *p = (unsigned char *)ptr;
	size_t i;
	unsigned char val = (unsigned char)value;

	for (i = 0; i < num; i++)
	{
		p[i] = val;
	}

	return (ptr);
}

/**
 * _realloc - re-allocate the memory.
 * @ptr: the string needs to be re-allocated.
 * @size: the new size.
 * @old_size: the old size.
 * Return: void.
 */

void *_realloc(void *ptr, size_t size, size_t old_size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		ptr = malloc(size);
		return (ptr);
	}

	new_ptr = malloc(size);
	if (new_ptr != NULL)
	{
		_memset(new_ptr, 0, size);
		_memcpy(new_ptr, ptr, old_size);

		free(ptr);
	}

	return (new_ptr);
}
