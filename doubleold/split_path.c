#include "shellshocked.h"

int get_size(char *temp)
{
	char *token = NULL;
	char *delim = ":";
	int count = 1;

	token = strtok(temp, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		count++;
	}
	return (count);
}

/**
 * split_path - Splits the path variable into tokens
 * @temp_path: The copy of the PATH variable
 * @tokens: The array of path directories
 *
 * Return: 1 on success
 */

int split_path(char *temp_path, char **tokens)
{
	char *delim = ":";
	char *token = NULL;
	int i = 0;

	token = strtok(temp_path, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	return (1);
}
