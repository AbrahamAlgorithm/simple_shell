#include "shells.h"

/**
 * _strcpy - Copies one string to another
 * @path: The destination string
 * @source: The source string
 *
 * Return: Pointer to the path string
 */
char *_strcpy(char *path, const char *source)
{
	char *path_ptr = path;

	for (; *source != '\0'; source++, path_ptr++)
	{
		*path_ptr = *source;
	}

	*path_ptr = '\0';

	return (path);
}

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if the strings are equal
 * +1 if s1 is greater
 * -1 is s2 is greater
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * _strconcat - Concatenates two strings
 * with a '/' char between them
 * @s1: The first string
 * @s2: The second string
 *
 * Return: A newly allocated string containing s1, '/', and s2
 */
char *_strconcat(const char *s1, const char *s2)
{
	char *result;
	size_t len1;
	size_t len2;
	size_t i;
	len1 = 0;
	len2 = 0;

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	result = (char *)malloc(len1 + len2 + 2);

	if (result == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		result[i] = s1[i];
	}

	result[len1] = '/';

	for (i = 0; i < len2; i++)
	{
		result[len1 + 1 + i] = s2[i];
	}

	result[len1 + len2 + 1] = '\0';

	return (result);
}

/**
 * _strlen - Calculate the length of a string
 * @str: The input string
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	if (!str)
		return (len);
	for (len = 0; str[len]; len++)
		;
	return (len);
}

