#include "shells.h"

/**
 *
 *
 *
 *
 */
int main(int ac, char **argv)
{
	char *prompt = "~$ ";
	char *lineptr = NULL;
	size_t len = 0;
	ssize_t nread;

        /* Declaring void variables */
        (void)ac;
	(void)argv;

	/* create an infinite loop */
	while (1)
	{
		printf("%s", prompt);

	        nread = getline(&lineptr, &len, stdin);

		if (nread == -1)
		{
			perror("getline"); /*Handles error if there is any*/
			break; /*Exit the loop om error*/
		}

	        printf("%s", lineptr);

		/*Free up the allocated memory*/
	        free(lineptr);
		lineptr = NULL; /*Reset thhe pointer to NuLL for safety*/
		len = 0; /*Reset the sixe to 0*/
	}
	
	return (0);
}
