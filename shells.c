#include "shells.h"

int main(void)
{
    while (1)
    {
        char **args = parse_input("~$ ");
        int status;

        if (args == NULL)
        {
            write(STDOUT_FILENO, "Error occurred while getting input.\n", 36);
            continue;
        }

        status = execute_command(args);

        if (status == -1)
        {
            write(STDOUT_FILENO, "Command not found.\n", 19);
        }

        int i;
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }
        free(args);
    }

    return (0);
}
