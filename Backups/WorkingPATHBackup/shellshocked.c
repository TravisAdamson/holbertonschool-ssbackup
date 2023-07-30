#include "shellshocked.h"

void init_tokens(void)
{
	int i = 0;

	for (i = 0; i < 10; i++)
		tokens[i] = NULL;
}
/**
 * main - Generates a simple shell
 * @argc: Number of arguements given
 * @argv: The arguements given
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int num_char, i;
	size_t bsize;
	char *user_input;
	char *name;
	char *path;
	int path_check = 0;

	bsize = 1024;
	i = 0;
	argc = 0;
	name = "PATH";
	path = NULL;
	init_tokens();
	user_input = malloc(bsize);
	if (user_input == NULL)
	{
		perror("Your memory is shellshocked, unable to continue");
		exit(1);
	}
	path = get_env(name, environ);
	while (1)
	{
		printf("%s", prompt);
		num_char = getline(&user_input, &bsize, stdin);
		if (num_char  == -1)
		{
			perror("\n\nYou have been shellshocked and your session has ended!\n");
			free(user_input);
			exit(100);
		}
		argc = get_token(user_input, argv);
		if (argc == 0)
			printf("You didn't enter any commands");
		path_check = split_path(path, tokens);
		if (path_check == 0)
			return (-1);
	}
	while (i < 10)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(user_input);
	return (0);
}
