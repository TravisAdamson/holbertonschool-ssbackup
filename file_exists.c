#include "shellshocked.h"

int check_file_exists(char *command, char **tokens)
{
	int exists, index;
	char *temp_command;

	index = 0;
	exists = 1;
	while ((exists == 1) && (tokens[index] != NULL))
	{
		temp_command = malloc(strlen(tokens[index]) + strlen(command));
		strcpy(temp_command, tokens[index]);
		strcat(temp_command, command);
		exists = access(temp_command, F_OK);
		free(temp_command);
		if (exists == 0)
			return (index);
		index++;
	}
	return (0);
}
