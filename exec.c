#include "shells.h"

/**
 * execute_command - execute commands if command is detected
 * @args: command to be executed
 */

int execute_command(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (access(args[0], X_OK) == 0)
	{
		pid_t child = fork();

		if (child == -1)
		{
			perror("problem");
			return (-1);
		} else if (child == 0)
		{
			execve(args[0], args, environ);
			perror("execve");
			_exit(EXIT_FAILURE);
		} else
		{
			int status, exit_status;

			waitpid(child, &status, 0);
			if ((status & 255) == 0)
				exit_status = (status >> 8) & 255;
			else
				exit_status = -1;
			return (exit_status);
		}
	} else
	{
		char path[256], *binDirectory = "/bin/";
		int i = 0, j = 0;

		while (binDirectory[i] != '\0')
		{
			path[i] = binDirectory[i];
			i++;
		}

		while (args[0][j] != '\0')
		{
			path[i] = args[0][j];
			i++;
			j++;
		}

		path[i] = '\0';
		if (access(path, X_OK) == 0)
		{
			pid_t child = fork();

			if (child == -1)
			{
				perror("problem");
				return (-1);
			} else if (child == 0)
			{
				execve(path, args, environ);
				perror("execve");
				_exit(EXIT_FAILURE);
			} else
			{
				int status;
				int exit_status;

				waitpid(child, &status, 0);
				if ((status & 0xff) == 0)
					exit_status = (status >> 8) & 0xff;
				else
					exit_status = -1;
				return (exit_status);

			}
		} else
		{
			write(STDOUT_FILENO, "Command not found.\n", 19);
			return (-1);
		}
	}
}
