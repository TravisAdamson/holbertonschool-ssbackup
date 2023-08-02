#include "shellshocked.h"

/**
 * print_env - Builtin to print all env variables
 * @environ: The list of env variables
 *
 * Return: 0
 */
int print_env(char **environ)
{
	char **env = environ;
	
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * get_env - Aquire the desired env variable
 * @name: The env variable requested
 * @environ: The list of environment variables
 *
 * Return: THe requested env or NULL on failure
 */
char *get_env(char *name, char **environ)
{
	char **env2 = environ;
	char *temp = NULL;
	int index = 0;

	while (env2[index] != NULL)
	{
		if (strncmp(env2[index], name, strlen(name)) == 0)
		{
			temp = strchr(env2[index], '=') + 1;
			return (temp);
		}
		index++;
	}
	return (NULL);
}
