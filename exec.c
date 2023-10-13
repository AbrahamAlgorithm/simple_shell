#include "shells.h"

void execute_comand(const char *command)
{
	pid_t child_pid = fork ();

	if (child_pid == -1)
	{
		printf("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/*Child process*/
		char *args[] = {"/bin/sh", "-c", command, NULL};
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		/*Parent process*/
		int status;
		waitpid(child_pid, &status, 0);
	}
