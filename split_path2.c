#include "shellshocked.h"

int split_path(char *path, char **tokens)
{
	char *delim = ":";
	char *temp_path = strdup(path);
	char *temp_path2 = strdup(path);
	char *token = NULL;
	int i = 0;
	int j = 1;
	int token_length = 0;

	token = strtok(temp_path2, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		j++;
	}
	free(temp_path2);
	tokens = malloc(sizeof(char *) * (j + 1));
	token = strtok(temp_path, delim);
	while (token != NULL)
	{
		token_length = strlen(token) + 1;
		tokens[i] = malloc(token_length);
		strcpy(tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	free(temp_path);
	return (1);
}
