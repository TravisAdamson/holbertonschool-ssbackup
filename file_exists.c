#include "shellshocked.h"

int check_file_exists(char *command, char **tokens)
{
	int exists, index;
	char *temp_command;

	index = 0;
	exists = 1;
	temp_command = tokens[index];
	strcat(temp_command, command);
	exists = access(temp_command, F_OK);
	if (exists != 0)
		index++;
	while ((exists == 1) && (temp_command != NULL))
	{
		temp_command = tokens[index];
		strcat(temp_command, command);
		exists = access(temp_command, F_OK);
		if (exists == 0)
			break;
		index++;
	}
	return (index);
}
