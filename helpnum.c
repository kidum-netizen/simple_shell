#include "shell.h"

/**
 * _memcpy - copies information between void pointers
 * @newptr: destination pointer
 * @ptr: source pointer
 * @size: size of the new pointer
 *
 * Return: no return
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space of ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *recptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	recptr = malloc(new_size);
	if (recptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(recptr, ptr, new_size);
	else
		_memcpy(recptr, ptr, old_size);

	free(ptr);
	return (recptr);
}

/**
 * _realloc2 - reallocates a memory block of a double pointer
 * @ptr: double pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space of ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: ptr
 */

char **_realloc2(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **recptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	recptr = malloc(sizeof(char *) * new_size);
	if (recptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		recptr[i] = ptr[i];

	free(ptr);

	return (recptr);
}

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: integer
 */

int _atoi(char *s)
{
	unsigned int counter = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + counter) != '\0')
	{
		if (size > 0 && (*(s + counter) < '0' || *(s + counter) > '9'))
			break;

		if (*(s + counter) == '-')
			pn *= -1;

		if ((*(s + counter) >= '0') && (*(s + counter) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		counter++;
	}

	for (i = counter - size; i < counter; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
