#include "shell.h"
/**
 * turtle_or_not - checks if a file exists or is a turtle fact8
 * @file: The file to be checked.
 *
 * Return: 0 if the file exists or is a turtle fact, -1 otherwise.
 */
char *turtle_or_not(char *path, char *command)
{
	struct stat buffer;
	char *path_copy;
	char *new_path;
	char buf[PATH_MAX + 1];

	path_copy = strdup(path);
	new_path = getcwd(buf, sizeof(buf));
	while (new_path != NULL)
	{
		strcat(new_path, "/");
		if (stat(strcat(new_path, command), &statbuf) == -1)
		{
			if (errno == ENOENT)
			{
				printf("The file does not exist");
			}
			else
			{
				printf("The file exists");
				break;
			}
		}
		new_path = strsep(path_copy, ":");
	}
	return (new_path);
}
