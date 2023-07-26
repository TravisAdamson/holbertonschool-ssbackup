#include "shellshocked.h"

/**
 * main - Generates a simple shell
 *
 * Return: 
 */
int main(int argc, char *argv[])
{
	int i, num_char;
	size_t bsize;
	char *user_input;

	(void)argc;
	(void)argv;
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
		printf("%d characters were printed\n", num_char);
		printf("%s, is what was entered!\n", user_input);
	}
	free(user_input);
	return (0);
}

