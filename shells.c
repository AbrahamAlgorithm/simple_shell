#include "shells.h"

/**
 * main - main entry point
 *
 * Return: 0 on success
 *        -1 on failure
 */
int main(void)
{
	while (1)
	{
		char **args = parse_input("~$ ");
		int status;
		int i;

		if (args == NULL)
		{
			write(STDOUT_FILENO, "Error occurred while getting input.\n", 36);
			continue;
		}

		if (strcmp(args[0], "env") == 0)
		{
			print_environment();
		}
		else
		{
			status = execute_command(args);
			if (status == -1)
			{
				write(STDOUT_FILENO, "Command not found.\n", 19);
			}
		}

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}

	return (0);
}
