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
	char *temp_token, *temp_input, *save_ptr;
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
	save_ptr = malloc((count + 1) * sizeof(char *));
	if (save_ptr == NULL)
	{
		free(temp_token);
		free(temp_input);
		return (0);
	}
	argv[index] = NULL;
	argv[index] = strtok(user_input, " ");
	index++;
	while (index < count)
	{
		argv[index] = NULL;
		argv[index] = strtok(NULL, " ");
		index++;
	}
	argv[index] = NULL;
	free(temp_token);
	free(temp_input);
	return (count);
}

