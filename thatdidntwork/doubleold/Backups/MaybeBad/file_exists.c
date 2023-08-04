#include "shellshocked.h"

#include <sys/stat.h>
#include <dirent.h>

/**
 * check_file_exists - Checks to see if the command exists
 * @command: The entered command by the user
 * @dir_name: A dir in PATH
 *
 * Return: 1 on success, 0 on failure
 */
int check_file_exists(char *command, char *dir_name)
{
	DIR *dir;
	struct dirent *list;

	dir = opendir(dir_name);
	if (dir == NULL)
		return (0);
	while ((list = readdir(dir)) != NULL)
	{
		if (strcmp(list->d_name, command) == 0)
		{
			printf("File found");
			closedir(dir);
			return (1);
		}
	}
	printf("File not found");
	closedir(dir);
	return (0);
}
