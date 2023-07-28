#include "shellshocked.h"

int print_env(char **environ)
{
	char **env = environ;
	printf("started  -- int print_env(**environ)");
	while (*env != NULL) 
	{
		printf("%s\n", *env);
		env++;
	}
	printf("ended  -- int print_env(**environ)");
	return (0);
}

char *get_env(char *name, char **environ)
{
	char **env = environ;
	char *temp = NULL;
	while (!*env)
	{
		printf("*env = \n%s\n", *env);
		printf("*environ = \n%s\n", *environ);
		if (*env != NULL && strncmp(*env, name, strlen(name)) == 0)
		{
			temp = strchr(*env, '=') + 1;
			printf("PATH(temp) = %s\n", temp);
			return(temp);
		}
		env++;
	}
	return (NULL);
}
