#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_path(char *path)
{
	char **paths = NULL;
	char *temp_path = strdup(path);
	char *temp_path2 = strdup(path);
	char *token;
	int i = 0;
	
	token = strtok(temp_path, ":");
	while (token != NULL)
	{
		token = strtok(NULL, ":");
		i++;
	}
	paths = malloc(sizeof(char *) * (i + 1));
	if (paths == NULL)
		return (NULL);
	free(temp_path);
	i = 0;
	token = strtok(temp_path2, ":");
	while (token != NULL)
	{
		paths[i] = strdup(token);
		if (paths[i] == NULL)
		{
			while (i >= 0)
			{
				free(paths[i]);
				i--;
			}
			free(paths);
			return (NULL);
		}
		token = strtok(NULL, ";");
		i++;
	}
	paths[i] = NULL;
	free(temp_path2);
	return (paths);
}
