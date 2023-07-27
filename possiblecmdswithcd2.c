#include "shellshocked.h"

int check_run(char **argv)
{
    pid_t pid = fork();
    int status = 0;
  
    /* char *com = "ls -la --color=auto";*/
/* system(com);*/
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
    return (0);
}
