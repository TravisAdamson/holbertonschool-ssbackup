#include "shellshocked.h"

int split_path(char *path, char **tokens)
{
	char *delim = ":";
	char *temp_path = strdup(path);
	char *token = NULL;
	int i = 0;
	int j = 0;
	int token_length = 0;

	printf("Temp_Path = %s\n", temp_path);
	token = strtok(temp_path, delim);
	while (token != NULL)
	{
		printf("Token = %s\n", token);
		token_length = strlen(token) + 1;
		tokens[i] = malloc(token_length);
		strcpy(tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	free(temp_path);
	for (j = 0; j < i + 1; j++)
		printf("tokens[%d] = %s\n", j, tokens[j]);
	return (1);
}
