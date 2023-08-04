#include "shellshocked.h"

int main(int argc, char **argv)
{
	size_t bsize = 1024;
	int path_size, num_char, index, exists, test;
	char *user_input, *path, *temp_path, *temp_input;
	char *temp_com, *temp_dir, *delim;

	(void)argv;
	delim = ":";
	test = 1;
	user_input = malloc(bsize);
	if (user_input == NULL)
	{
		perror("Your memory is shellshocked");
		exit(1);
	}
	path = get_env("PATH", environ);
	temp_path = strdup(path);
	path_size = get_size(temp_path, delim);
	free(temp_path);
	tokens = malloc(sizeof(char *) * (path_size + 1));
	temp_path = strdup(path);
	split_path(temp_path, tokens);
	free(temp_path);
	while (1)
	{
		printf("%s", prompt);
		num_char = getline(&user_input, &bsize, stdin);
		if (num_char == -1)
		{
			perror("\n\nYou have been shellshocked!\n");
			break;
		}
		delim = " ";
		temp_input = strdup(user_input);
		input_size = get_size(temp_input, delim);
		free(temp_input);
		input_tokens = malloc(sizeof(char *) * (input_size + 1));
		temp_input = strdup(user_input);
		get_token(temp_input, input_tokens);
		free(temp_input);
		if (input_size == 0)
			printf("You didn't enter any commands");
		else
		{
			temp_com = strdup(input_tokens[0]);
			while (test == 1)
			{
				temp_dir = strdup(tokens[index]);
				if (temp_dir == NULL)
				{
					free(temp_dir);
					test = 2;
					break;
				}
				exists = check_file_exists(temp_com,temp_dir);
				if (exists != 0)
				{
					printf("The command exists in tokens[%d]\n", index);
					free(temp_dir);
					break;
				}
				else
					index++;
				free(temp_dir);
			}
			free(temp_com);
		}
		free(temp_input);
		test = 1;
		argc = 1;
		num_char = 1;
	}
	free(tokens);
	free(user_input);
	return (0);
}
