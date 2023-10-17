#include "shells.h"

/**
 * print_environment - This function displays environment variables
 *
 * Return: Always returns 0.
 */
int print_environment(void)
{
	extern char **environ;
	
	int i;
	
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	
	return (0);
}
