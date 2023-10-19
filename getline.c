#include "shells.h"

void *_realloc(void *ptr, unsigned int old_sizes, unsigned int new_sizes);
void allocate_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_sizes: The size in bytes of the allocated space for ptr.
 * @new_sizes: The size in bytes for the new memory block.
 *
 * Return: If new_sizes == old_sizes - ptr.
 * If new_sizes == 0 and ptr is not NULL - NULL.
 * Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_sizes, unsigned int new_sizes)
{
	void *mem = NULL;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_sizes == old_sizes)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_sizes);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_sizes == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_sizes && index < new_sizes; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}

/**
 * allocate_lineptr - allocates the lineptr variable.
 * @lineptr: A buffer to store an input.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void allocate_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	allocate_lineptr(lineptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
