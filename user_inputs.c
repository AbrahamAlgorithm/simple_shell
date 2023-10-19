#include "shells.h"
/**
 * parse_input - this function displays the input
 * to the terminal and parse it
 * @prompt: the prompt to be displayed
 * Return: the array of tokens
 */
char **parse_input(const char *prompt)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t response;
	char **tokens = NULL;
	size_t token_count = 0;
	char *token = NULL;
	char **temp;

	write(STDOUT_FILENO, prompt, strlen(prompt));
	response = getline(&input, &input_size, stdin);
	if (response == -1)
	{
		perror("parse_input: getline");
		free(input);
		exit(EXIT_FAILURE);
	} else if (response == 0)
	{
		write(STDOUT_FILENO, "EOF detected. Exiting the shell.\n", 34);
		free(input);
		exit(EXIT_SUCCESS);
	}
	token = strtok(input, " \n");
	while (token != NULL)
	{
		char **temp = realloc(tokens, (token_count + 1) * sizeof(char *));

		if (temp == NULL)
		{
			perror("parse_input: realloc");
			exit(EXIT_FAILURE);
		}
		tokens = temp;
		tokens[token_count] = malloc(strlen(token) + 1);
		if (tokens[token_count] == NULL)
		{
			perror("parse_input: malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[token_count], token);
		token_count++;
		token = strtok(NULL, " \n");
	}
	temp = realloc(tokens, (token_count + 1) * sizeof(char *));
	if (temp == NULL)
	{
		perror("parse_input: realloc");
		exit(EXIT_FAILURE);
	}
	tokens = temp;
	tokens[token_count] = NULL;
	free(input);
	return (tokens);
}
