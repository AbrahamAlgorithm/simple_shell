#include "shells.h"

void execute_comand(const char *command)
{
    if (command == NULL || command[0] == '\0')
    {
        return;
    }

    char *args[64]; // Adjust the array size as needed
    int arg_count = 0;

    // Tokenize the command into arguments
    char *token = strtok((char *)command, " ");
    while (token != NULL && arg_count < 63)
    {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL; // Null-terminate the array

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] != NULL)
	{
            if (chdir(args[1]) != 0)
	    {
                perror("cd");
            }
        }
    }
    else
    {
        pid_t child = fork();

        if (child == -1)
	{
            perror("fork");
        }
	else if (child == 0)
	{
            // Child process
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
	else
	{
            // Parent process
            int status;
            waitpid(child, &status, 0);
        }
    }
}
