#include "shellshocked.h"

/**
 * get_token - Tokenizes the user input
 * @user_input: The input to be tokenized
 * @argv: Where to store the tokens
 *
 * Return: The number of arguments
 */
int get_token(char *user_input, char **argv)
{
	char *temp_token, *temp_input, *save_ptr;
	int count, index;

	printf("started int get_token(char *user_input, char **argv)")
	index = 1;
	temp_input = strdup(user_input);
	save_ptr = NULL;
	if (temp_input == NULL)
		return (0);
	temp_token = strtok_r(temp_input, " ", &save_ptr);
	count = 1;
	while (temp_token != NULL)
	{
		temp_token = strtok_r(NULL, " ", &save_ptr);
		count++;
	}
	argv[index] = NULL;
	argv[index] = strtok_r(user_input, " ", &save_ptr);
	index++;
	while (index < count)
	{
		argv[index] = NULL;
		argv[index] = strtok_r(NULL, " ", &save_ptr);
		index++;
	}
	argv[index] = NULL;
	free(temp_token);
	free(temp_input);
	 printf("ended int get_token(char *user_input, char **argv)")

	return (count);
}
/**
 * get_token2 - Tokenizes the user input
 * @user_input: The input to be tokenized
 * @argv: Where to store the tokens
 *
 * Return: The pointer to the new array
 */
char **get_token2(char *path)
{
        char *temp_tokens, *temp_inputs, *save_ptrs;
        int counts, indexs;
	char **full_paths = NULL;

        indexs = 0;
        temp_inputs = strdup(path);
        save_ptrs = NULL;
        if (temp_inputs == NULL)
                return (0);
        temp_tokens = strtok_r(temp_inputs, " ", &save_ptrs);
        counts = 1;
        while (temp_tokens != NULL)
        {
                temp_tokens = strtok_r(NULL, " ", &save_ptrs);
                counts++;
        }
	free(temp_inputs);
	temp_inputs = strdup(path);
	*full_paths = malloc((counts + 1) * sizeof(char *));
        full_paths[indexs] = NULL;
        full_paths[indexs] = strtok_r(temp_inputs, " ", &save_ptrs);
        indexs++;
        while (indexs < counts)
        {
                full_paths[indexs] = NULL;
                full_paths[indexs] = strtok_r(NULL, " ", &save_ptrs);
                indexs++;
        }
        full_paths[indexs] = NULL;
        free(temp_tokens);
        free(temp_inputs);
        return (full_paths);
}
