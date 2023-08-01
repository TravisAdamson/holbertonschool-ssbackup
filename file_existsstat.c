#include "shellshocked.h"

#include "shellshocked.h"
#include <sys/stat.h>

int check_file_exists(char *command, char *dir_name)
{
	char *full_path;
	struct stat path_stat;

	full_path = malloc(strlen(command) + strlen(dir_name) + 2);
	full_path = dir_name;
	strcat(full_path, "/");
	strcat(full_path, command);
	if (stat(full_path, &path_stat) != 0)
	{
		free(full_path);
		return (0);
	}
	if (S_ISDIR(path_stat.st_mode))
	{
		printf("Directory found\n");
		free(full_path);
		return (1);
	}
	else if (S_ISREG(path_stat.st_mode))
	{
		printf("File found\n");
		free(full_path);
		return (1);
	}
	else
	{
		printf("Not a file or directory\n");
		free(full_path);
		return (0);
	}
}
