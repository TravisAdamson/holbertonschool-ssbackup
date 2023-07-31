#include "shellshocked.h"

#include <sys/stat.h>
#include <dirent.h>

int check_file_exists(char *command, char **tokens)
{
	int i;
	char *full_path;

	for (i = 0; tokens[i] != NULL; i++)
	{
		full_path = malloc(strlen(tokens[i]) + strlen(command) + 2);
		strcpy(full_path, tokens[i]);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, F_OK) == 0) 
		{
			printf("The file, %s, can be found in %s", command, tokens[i]);
			free(full_path);
			return (i);
		}
		free(full_path);
	}
	return (0);
}
