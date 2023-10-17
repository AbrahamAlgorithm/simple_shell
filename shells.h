#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **argv);
int execute_command(char **args);

#endif /*_SHELL_H_*/
