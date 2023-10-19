#include "shells.h"

/**
 * similar - checks if character matches any value in string
 * @chr: character
 * @string: string
 *
 * Return: 1 if match, 0 if not
 */
unsigned int similar(char chr, const char *string)
{
	unsigned int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (chr == string[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - my version of the strtok function
 * @str: string tokenized
 * @delim: splitter
 *
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next;
	unsigned int i;

	if (str != NULL)
		next = str;
	token = next;
	if (token == NULL)
		return (NULL);
	for (i = 0; next[i] != '\0'; i++)
	{
		if (similar(next[i], delim) == 0)
			break;
	}
	if (next[i] == '\0' || next[i] == '#')
	{
		next = NULL;
		return (NULL);
	}
	token = next + i;
	next = token;
	for (i = 0; next[i] != '\0'; i++)
	{
		if (similar(next[i], delim) == 1)
			break;
	}
	if (next[i] == '\0')
		next = NULL;
	else
	{
		next[i] = '\0';
		next = next + i + 1;
		if (*next == '\0')
			next = NULL;
	}
	return (token);
}
