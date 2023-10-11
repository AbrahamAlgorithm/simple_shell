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
	char *lineptr;
	size_t len = 0;

        /* Declaring void variables */
        (void)ac;
	(void)argv;

	/* create an infinite loop */
	while (1)
	{
		printf("%s", prompt);
	        getline(&lineptr, &len, stdin);
	        printf("%s", lineptr);

	        free(lineptr);
	}
	return (0);
}
