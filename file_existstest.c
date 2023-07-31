#include "shellshocked.h"

int check_file_exists(char *command, char **tokens)
{
        int exists, index;
        char *temp_command;
	char *slash = "/";
        struct stat buffer;

        index = 0;
        exists = 1;
        while ((exists == 1) && (tokens[index] != NULL))
        {
                temp_command = malloc(strlen(tokens[index]) + strlen(command) + 2);
                strcpy(temp_command, tokens[index]);
		strcat(temp_command, slash);
                strcat(temp_command, command);
                exists = stat(temp_command, &buffer);
                free(temp_command);
                if (exists == 0)
                        return (index);
                index++;
        }
        return (0);
}
