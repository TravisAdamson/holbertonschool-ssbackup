#include "shellshocked.h"

int check_file_exists(char *command, char **tokens)
{
	int exists, index;
	char *temp_command, *temp_command2;

	index = 0;
	exists = 1;
	temp_command = tokens[index];
	temp_command2 = command;
	strcat(temp_command, temp_command2);
	exists = access(temp_command, F_OK);
	if (exists != 0)
		index++;
	while ((exists == 1) && (temp_command != NULL))
	{
		temp_command = tokens[index];
		temp_command2 = command;
		strcat(temp_command, temp_command2);
		exists = access(temp_command, F_OK);
		if (exists == 0)
			break;
		index++;
	}
	return (index);
}
