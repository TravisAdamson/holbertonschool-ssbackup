#include "shellshocked.h"

/**
 * main - Generates a simple shell
 * @argc: Number of arguements given
 * @argv: The arguements given
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int num_char, path_size, index, exists;
	size_t bsize;
	char *user_input;
	char *name, *temp_com, *temp_dir;
	char *path, *temp_path;

	bsize = 1024;
	argc = 0;
	exists = 0;
	name = "PATH";
	path = NULL;
	index = 0;
	user_input = malloc(bsize);
	if (user_input == NULL)
	{
		perror("Your memory is shellshocked, unable to continue");
		exit(1);
	}
	path = get_env(name, environ);
	temp_path = strdup(path);
	path_size = get_path_size(temp_path);
	free(temp_path);
	tokens = malloc(sizeof(char *) * path_size);
	temp_path = strdup(path);
	split_path(temp_path, tokens);
	free(temp_path);
	while (1)
	{
		index = 0;
		exists = 0;
		num_char = 0;
		argc = 1;
		printf("%s", prompt);
		num_char = getline(&user_input, &bsize, stdin);
		if (num_char  == -1)
		{
			perror("\n\nYou have been shellshocked and your session has ended!\n");
			break;
		}
		argc = get_token(user_input, argv);
		if (argc == 0)
			printf("You didn't enter any commands");
		else
		{
			while (tokens[index] != NULL)
			{
				temp_com = strdup(argv[1]);
				temp_dir = strdup(tokens[index]);
				exists = check_file_exists(argv[1], tokens[index]);
				if (exists != 0)
				{
					printf("The command exists in tokens[%d]\n", index);
					free(temp_com);
					free(temp_dir);
					break;
				}
				else
					index++;
				free(temp_com);
				free(temp_dir);
			}
		}
	}
	free(tokens);
	free(user_input);
	return (0);
}
