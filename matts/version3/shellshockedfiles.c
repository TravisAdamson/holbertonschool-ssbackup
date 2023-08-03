#include "shell.h"

/**
 * readPrompt - gets line from input and maintains prompt
 * @prmptStyle: How we want the prompt to look
 * @input: input received from stdin
 * @len: the length of the input from stdin
 * Return: the number of characters read
 */

ssize_t readPrompt(const char *prmptStyle, char **input, size_t *len)
{
    ssize_t gotLine = 0;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, prmptStyle, strlen(prmptStyle));

    gotLine = getline(input, len, stdin);
    if (gotLine == EOF)
        return (-1);
    if (gotLine == 0)
        return (1);

    return (gotLine);
}

#include "shell.h"

/**
 * parseInput - parses/tokenizes input into string vector
 * @input: object string
 * @cmdS: destination string vector
 * @delim: delimiter to be fed to splitting/tokenizing function
 * Return: 0 if input parsed to cmdS, -1 otherwise
 */

int parseInput(char *input, char *cmdS[], char *delim)
{
    int iter = 0;
    char *cmdT = NULL, *dup = NULL;

    for (dup = input, iter = 0; (cmdT = shell_cracked(&dup, delim)); iter++)
    {
        cmdS[iter] = cmdT;
        if (strcmp("exit", cmdS[0]) == 0)
        {
            set_turtle_free_or_not(cmdS);
            if (input)
                free(input);
            exit(0);
        }
    }
    if (cmdT != NULL)
        cmdT = NULL;

    if (dup != NULL)
        free(dup), dup = NULL;

    return (*cmdS ? 0 : -1);
}

#include "shell.h"

/**
 * main - infinite loop for prompt
 * Return: Always 0
 */

int main(void)
{
    char *input = NULL;
    size_t inputLen = 0;
    int prmptChk = 0;
    char *cmdS[BUFSIZ] = { NULL };

    while (1)
    {
        signal(SIGINT, handle_turtle_interrupt);

        prmptChk = readPrompt("# ", &input, &inputLen);
        if (prmptChk == -1)
            free(input), exit(0);
        else if (prmptChk == 1)
            continue;

        if (empty_turtle_shell(input) == 0)
        {
            free(input), input = NULL;
            continue;
        }

        parseInput(input, cmdS, SPC_DELIM);

        turtle_cross_road_or_not(input, cmdS);

        set_turtle_free_or_not(cmdS);

        if (input != NULL)
            free(input), input = NULL;

        fflush(stdout);
    }
    return (0);
}

