#include "shellshocked.h"

/**
 * main - Generates a simple shell
 *
 * Return: 
 */
int main()
{
	int i, num_char;
	size_t bsize;
	char *user_input;
	char *token;
	char *com = "ls";

	i = 0;
	bsize = 1024;
	user_input = malloc(bsize);
	if (user_input == NULL)
	{
		perror("Your memory is shellshocked, unable to continue");
		exit(1);
	}
	while (i != 15)
	{
		printf("%s", prompt);
		num_char = getline(&user_input, &bsize, stdin);
		if (num_char == 1)
			i = 15;
		token = strtok(user_input, " ");
		if (token)
			system(com);
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
	}
	free(user_input);
	return (0);
}

