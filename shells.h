#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* Shell Terminal */
int main(void);
int execute_command(char **args);
char **parse_input(const char *prompt);

/* Environment Built-ins */
int print_environment(void);

#endif /*_SHELL_H_*/
