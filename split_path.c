#include "shellshocked.h"

char **split_path(char *path)
{
	char **paths = NULL;
	char *temp_path = path;
	char *temp_path2 = path;
	char *token;
	int i = 1;
	char *save_point = NULL;
	
	printf("PATH = %s", path);
	token = strtok_r(temp_path, ":", &save_point);
	while (token != NULL)
	{
		token = strtok_r(NULL, ":", &save_point);
		i++;
	}
	paths = malloc(sizeof(char *) * (i + 2));
	if (paths == NULL)
		return (NULL);
	free(temp_path);
	i = 0;
	token = strtok_r(temp_path2, ":", &save_point);
	while (token != NULL)
	{
		paths[i] = token;
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
		token = strtok_r(NULL, ";", &save_point);
		i++;
	}
	paths[i] = NULL;
	free(temp_path2);
	return (paths);
}
