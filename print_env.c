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
	char *temp = NULL;
	while (*env != NULL)
	{
		printf("This is a test\n");
		printf("strlen(%s) = %ld\n", name, strlen(name));
		if (strncmp(*env, name, strlen(name)) == 0)
		{
			temp = (strchr(*env, '=') +1);
			printf("PATH = %s\n", temp);
			return(temp);
		}
		env++;
	}
	return (NULL);
}
