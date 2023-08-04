#include "shellshocked.h"

/**
 * get_token - Tokenizes the user input
 * @user_input: The input to be tokenized
 * @argv: Where to store the tokens
 *
 * Return: The number of arguments
 */
int get_token(char *user_input, char **argv)
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
	free(temp_token);
	free(temp_input);
	temp_input = strdup(user_input);
	temp_token = strtok(temp_input, " ");
	argv[index] = strdup(temp_token);
	index++;
	while (index < count)
	{
		temp_token = strtok(NULL, " ");
		argv[index] = strdup(temp_token);
		index++;
	}
	argv[index] = NULL;
	free(temp_token);
	free(temp_input);
	return (count);
}
