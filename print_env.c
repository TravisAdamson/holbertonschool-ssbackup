#include "shellshocked.h"

int print_env(char **environ)
{
	char **env = environ;
	printf("*env = \n%s\n", *env);
        printf("*environ = \n%s\n", *environ);
	while (*env != NULL) 
	{
		printf("%s\n", *env);
		env++;
	}
	printf("ended  -- int print_env(**environ)");
	return (0);
}

char *get_env(char *name)
{
	char **env2 = environ;
	int index = 0;

	while (env2[index] != NULL)
	{
		if (strncmp(env2[index], name, strlen(name)) == 0)
		{
			return(strchr(env2[index], '=') + 1);
		}
		index++;
	}
	return (NULL);
}
