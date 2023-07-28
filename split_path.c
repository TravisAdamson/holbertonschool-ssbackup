#include "shellshocked.h"

char **split_path(char *path)
{
	char **temp = NULL;
	char *temp_path = strdup(path);
	char *temp_path2 = strdup(path);
	char *token;
	int i = 1;
	char *save_point = NULL;
	
	token = strtok_r(temp_path, ":", &save_point);
	while (token != NULL)
	{
		token = strtok_r(NULL, ":", &save_point);
		i++;
	}
	temp = malloc(sizeof(char *) * (i + 1));
	if (temp == NULL)
		return (NULL);
	i = 1;
	token = strtok_r(temp_path2, ":", &save_point);
	while (token != NULL)
	{
		temp[i] = token;
		printf("Token [%d] = %s\n", i, token);
		token = strtok_r(NULL, ";", &save_point);
		i++;
	}
	temp[i] = NULL;
	free(temp_path);
	free(temp_path2);
	return (temp);
}
