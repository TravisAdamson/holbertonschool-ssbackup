#include "shellshocked.h"

#include <sys/stat.h>
#include <dirent.h>

int check_file_exists(char *command, char **tokens)
{
        int index;
	DIR *dir;
	struct dirent *list;

	index = 0;
	while (tokens[index] != NULL)
	{
		dir = opendir(tokens[index]);
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
		}
		closedir(dir);
		index++;
	}
	return (0);
}
