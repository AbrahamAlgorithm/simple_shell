#include "shells.h"

int execute_command(char **args)
{
	char command_path[100];

	/* Check if the command is not specified */
	if (args[0] == NULL)
	{
		return (0); /* Successful execution */
	}

	/* Check if it's a 'cd' command */
	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			/* Change to the home directory */
			if (chdir(getenv("HOME")) != 0)
			{
				perror("cd");
				return (-1); /* Error */
			}
		}
		else
		{
			/* Change to the specified directory */
			if (chdir(args[1]) != 0)
			{
				perror("cd");
				return (-1); /* Error */
			}
		}
		return (0); /* Sucessful Execution */
	}
	/* Check if the command is found in the current directory */
	if (access(args[0], X_OK) == 0)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			/* Inside the child process */
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("fork");
			return (-1);
		}
		else
		{
			/* Inside the parent process */
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				return WEXITSTATUS(status);
			}
		}
		return (-1);
    }

	_strcpy(command_path, "/bin/");
	_strconcat(command_path, args[0]);

	if (access(command_path, X_OK) == 0)
	{
		pid_t pid;
		pid = fork();
		if (pid == 0) 
		{
			/* Inside the child process */
			if (execve(command_path, args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("fork");
			return (-1);
		}
		else
		{
			/* Inside the parent process */
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				return WEXITSTATUS(status);
			}
		}
		return (-1);
    }
    
    /* Command not found */
	write(STDOUT_FILENO, "No such file or directory\n", _strlen("No such file or directory\n"));
	return (-1);
}
