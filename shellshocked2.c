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
	char *user_input, *temp_input;
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
	while (1)
	{
		printf("%s", prompt);
		num_char = getline(&user_input, &bsize, stdin);
		if (num_char  == -1)
		{
			perror("You have been shellshocked and your session has ended!\n")
			exit(100);
		}
		temp_input = strdup(user_input);
	}
	free(user_input);
	return (0);
}

