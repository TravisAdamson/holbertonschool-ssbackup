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

char *get_env(char *name)
{
	char **env = environ;
	while (*eviron != NULL)
	{
		if (strncmp(*environ, name, strlen(name)) == 0)
			return(strchr(*environ, '=') +1);
		environ++;
	}
	return (NULL);
}
