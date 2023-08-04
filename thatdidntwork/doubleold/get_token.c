#include "shellshocked.h"

/**
 * get_token - Tokenizes the user input
 * @user_input: The input to be tokenized
 * @argv: Where to store the tokens
 *
 * Return: The number of arguments
 */
int get_token(char *temp_input, char **input_tokens)
{
	int index;

	index = 0;
	token = strtok(user_input, " ");
	input_tokens[index] = strdup(token);
	index++;
	while (token != NULL)
	{
		tokens = strtok(NULL, " ");
		input_tokens[index] = strdup(token);
		index++;
	}
	input_tokens[index] = NULL;
	return (0);
}
