#include "shell.h"

/**
 * turtle_cross_road_or_not - launches input command with its arguments
 * @input: The command to be executed.
 * @argv: The arguments to the command.
 * Return: void
 */
void turtle_cross_road_or_not()
{
	pid_t launch = 0;
	int status = 0;
	char *path;
	char *full_path;

	path = get_path(environ);
	full_path = turtle_or_not(argv[0], path);
	if (full_path == NULL)
		exit(2);
	launch = fork();
	if (launch == -1)
		perror(argv[0]), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execvp(argv[0], argv) == -1)
			perror(argv[0]), free(input), exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
