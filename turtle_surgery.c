#include "shell.h"
/**
 * turtle_surgery - parses/tokenizes input into string vector
 * @input: object string
 * @cmdS: destination string vector
 * @delim: delimiter to be fed to splitting/tokenizing function
 *
 * Return: 0 if input parsed to cmdS, -1 otherwise
 */

int turtle_surgery(char *input, char **cmdS, char *delim)
{
	int iter = 0;
	int st = 0;
	char *cmdT = NULL, *dup = NULL;

	for (dup = input, iter = 0; (cmdT = shell_cracked(&dup, delim)); iter++)
	{
		cmdS[iter] = cmdT;
		if (strcmp("exit", cmdS[0]) == 0)
		{
			set_turtle_free_or_not(cmdS);
			if (input)
			{
				st = 2;
				free(input);
			}
			exit(st);
		}
	}
	if (cmdT != NULL)
		cmdT = NULL;
	if (dup != NULL)
		free(dup), dup = NULL;
	return (*cmdS ? 0 : -1);
}
