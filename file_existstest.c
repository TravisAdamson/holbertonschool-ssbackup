#include "shellshocked.h"

#include <sys/stat.h>
#include <dirent.h>

int check_file_exists(char *command, char **tokens)
{
        int index = 0;
	char *dir_name = tokens[index];
	DIR *dir;
	struct dirent *list;

	while (tokens[index] != NULL)
	{
		dir_name = tokens[index];
		dir = opendir(dir_name);
		if (dir != NULL)
		{
			while ((list = readdir(dir)) != NULL)
			{
				if (strcmp(list->d_name, command) == 0)
				{
					printf("The file %s exists in the directory %s\n", command, tokens[index]);
					return (index);
				}
			}
			closedir(dir);
		}
		index++;
	}
	free(dir);
	return (0);
}
