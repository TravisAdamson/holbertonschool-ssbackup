#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_path(char *path)
{
	char **paths = NULL;
	char *temp_path = strdup(path);
	char *token;
	int i = 0;
	
	token = strtok(temp_path, ":");
	while (token != NULL)
	{
		paths = realloc(paths, sizeof(char *) * (i + 1));
		paths[i] = strdup(token);
		token = strtok(NULL, ":");
		i++;
	}
	paths = realloc(paths, sizeof(char *) * (i + 1));
	paths[i] = NULL;
	free(temp_path);
	
	return (paths);
}
