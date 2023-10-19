#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

/* Global Environment */
extern char **environ;

/* Shell Terminal */
int main(void);
int execute_command(char **args);
char **parse_input(const char *prompt);

/* Getline functions */
void *_realloc(void *ptr, unsigned int old_sizes, unsigned int new_sizes);
void allocate_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* String functions */
char *_strcpy(char *path, const char *source);
int _strcmp(const char *s1, const char *s2);
char *_strconcat(const char *s1, const char *s2);
size_t _strlen(const char *str);
char *_strchr(const char *str, char ch);

/* Environment Built-ins */
int print_environment(void);
int env(char **args, char __attribute__((__unused__)) **front);


#endif /*_SHELL_H_*/
