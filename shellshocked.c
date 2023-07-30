#include "shellshocked.h"

void init_tokens(void)
{
	int i = 0;

	for (i = 0; i < 10; i++)
		tokens[i] = NULL;
}

void free_tokens(int i)
{
	if (tokens[i] != NULL)
		free_tokens(i + 1);
	free(tokens[i]);
	free(tokens);
	return;
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
	int num_char;
	size_t bsize;
	char *user_input;
	char *name;
	char *path;

	bsize = 1024;
	argc = 0;
	name = "PATH";
	path = NULL;
	user_input = malloc(bsize);
	if (user_input == NULL)
	{
		perror("Your memory is shellshocked, unable to continue");
		exit(1);
	}
	path = get_env(name, environ);
	split_path(path, tokens);
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
	}
	free_tokens(0);
	free(user_input);
	free(path);
	return (0);
}
