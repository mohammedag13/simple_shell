#include "shell.h"

/**
 * append_string - appends the string.
 * @ds: a dynamic string.
 * @str: the string should be edited.
 * Return: void.
 */

void append_string(DynamicString *ds, const char *str)
{
	size_t strLength = _strlen((char *)str);
	size_t old_cap = ds->capacity;
	size_t newLength = ds->len + strLength;

	if (ds->str == NULL)
	{
	ds->capacity = newLength + 1;
	ds->str = (char *)malloc(ds->capacity * sizeof(char));
	ds->len = 0;
	}
	else if (newLength >= ds->capacity)
	{
	ds->capacity = newLength + 1;
	ds->str = (char *)_realloc(ds->str, ds->capacity * sizeof(char), old_cap);
	}

	_strncpy_size(ds->str + ds->len, str, strLength + 1);
	ds->len = newLength;
}

/**
 * append_char - appends the character.
 * @ds: a dynamic string.
 * @ch: the character should be edited.
 * Return: void.
 */

void append_char(DynamicString *ds, char ch)
{
	size_t old_cap = ds->capacity;

	if (ds->len + 1 >= ds->capacity)
	{
	ds->capacity = (ds->capacity == 0) ? 2 : ds->capacity * 2;
	ds->str = (char *)_realloc(ds->str, ds->capacity * sizeof(char), old_cap);
	}
	ds->str[ds->len] = ch;
	ds->len++;
	ds->str[ds->len] = '\0';
}

/**
 * free_ds - free the dynamic variable.
 * @ds: the variable should be freed.
 * Return: void.
 */

void free_ds(DynamicString *ds)
{
	free(ds->str);
	ds->str = NULL;
	ds->capacity = 0;
	ds->len = 0;
}


/**
 * clear - gives values to the struct.
 * @ds: the struct.
 * Return: void.
 */

void clear(DynamicString *ds)
{
	free(ds->str);
	ds->str = NULL;
	ds->capacity = 0;
	ds->len = 0;
	init_dynamic_string(ds, "");
}

/**
 * init_dynamic_string - initialize the dynamic string.
 * @ds: the dynamic string.
 * @init: the string used in initializing the string.
 * Return: void.
 */

void init_dynamic_string(DynamicString *ds, char *init)
{
	ds->str = NULL;
	ds->capacity = 0;
	ds->len = 0;
	ds->append_char = &append_char;
	ds->append_string = &append_string;
	ds->free = &free_ds;
	ds->clear = &clear;

	ds->append_string(ds, init);
}
