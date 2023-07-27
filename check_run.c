#include "shellshocked.h"
extern char **environ;

int check_run(char **argv, char *cwd)
{
	pid_t pid = fork();
	int status = 0;
	int index = 2;
	char **path_tokens;
	printf("starting check_run");
	cwd[strcspn(cwd, ":")] = ' ';
	path_tokens = get_token2(cwd);
	printf("started  -- int main(int argc, char *argv[]))");
	if (path_tokens == NULL)
		return (-1);
	while (argv[index] != NULL)
	{
		argv[index][strcspn(argv[index], "\n")] = '\0';
		index++;
	}
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(argv[1], argv);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	printf("ended  -- int main(int argc, char *argv[]))");
	return (1);
}

