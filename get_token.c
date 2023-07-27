#include "shellshocked.h"

/**
 * get_token - Tokenizes the user input
 * @user_input: The input to be tokenized
 * @argv: Where to store the tokens
 * @argc: Number of arguments in argv
 *
 * Return: 1 on sucess or 0 on fail
 */
int get_token(char *user_input, char **argv, int argc)
{
	char *temp_token, *temp_input;
	int count, index;

	index = 1;
	temp_input = strdup(user_input);
	if (temp_input == NULL)
		return (0);
	temp_token = strtok(temp_input, " ");
	count = 1;
	while (temp_token != NULL)
	{
		temp_token = strtok(NULL, " ");
		count++;
	}
	argc = count;
	argv = malloc(count * sizeof(char *));
	if (argv == NULL)
	{
		free(temp_token);
		free(temp_input);
		return (0);
	}
	argv[0] = strtok(user_input, " ");
	while (argv[index] != NULL)
	{
		argv[index] = strtok(NULL, " ");
		index++;
	}
	free(temp_token);
	free(temp_input);
	return (1);
}

