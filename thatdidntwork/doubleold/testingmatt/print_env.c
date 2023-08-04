#include "shellshocked.h"

void print_environment_variable(const char *variable_name, char *envp[])
{
	char *value = get_environment_variable(variable_name, envp);
	if (value != NULL)
	{
		printf("%s\n", value);
	}
	else
	{
		printf("Environment variable '%s' not found.\n", variable_name);
	}
}
