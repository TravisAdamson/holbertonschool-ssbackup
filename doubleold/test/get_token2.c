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
        char *temp_token, *temp_input, *save_ptr;
        int count, index;
	char **full_path = NULL;

        index = 0;
        temp_input = strdup(path);
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
	free(temp_input);
	temp_input = strdup(path);
	*full_path = malloc((count + 1) * sizeof(char *));
        full_path[index] = NULL;
        full_path[index] = strtok_r(temp_input, " ", &save_ptr);
        index++;
        while (index < count)
        {
                full_path[index] = NULL;
                full_path[index] = strtok_r(NULL, " ", &save_ptr);
                index++;
        }
        full_path[index] = NULL;
        free(temp_token);
        free(temp_input);
        return (full_path);
}
