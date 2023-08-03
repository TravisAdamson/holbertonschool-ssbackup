#include "shell.h"

/**
 * print_environment_variables - prints environmental variables
 * @environment_variables: an array of environmental variables
 *
 * Return: 0 upon success, -1 otherwise.
 */
int print_environment_variables(char **environment_variables)
{
	int iter = 0;

	for (; environment_variables != NULL &&
			*environment_variables != NULL; ++environment_variables)
	{
		if (environment_variables == NULL)
			printf("%s", *environment_variables);
		else
			printf("%s\n", *environment_variables);
	}
	return (iter > 0 ? 0 : -1);
}

/**
 * get_path - Find the PATH variable value
 * @environment_variables: Environment variable list
 *
 * Return: Path variable
 */
char *get_path(**environment_variables)
{
	char **env = environment_variables;
	char *temp = NULL;
	int index = 0;

	while (env[index] != NULL)
	{
		if (strncmp(env[index], name, "PATH") == 0)
		{
			temp = strchr(env[index], '=') + 1;
			return(temp);
		}
		index++;
	}
	return (NULL);
}
