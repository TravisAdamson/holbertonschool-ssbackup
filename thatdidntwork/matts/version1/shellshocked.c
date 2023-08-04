
#include "shell.h"

/**
 * builtIn_cd - changes current working directory
 * @path: desired destination working directory
 * Return: 0 upon success, -1 otherwise
 */

int builtIn_cd(char *path)
{
    return (chdir(path));
}

#include "shell.h"

/**
 * handleSignal - checks for SIGINT
 * @sig: signal
 */

void handleSignal(int sig)
{
    char *prmptStyle = "\n# ";

    if (sig == SIGINT)
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, prmptStyle, strlen(prmptStyle));
}

#include "shell.h"

/**
 * builtIn_env - prints environmental variables
 * Return: 0 upon success, -1 otherwise
 */

int builtIn_env(void)
{
    char **ourEnv = NULL;
    int iter = 0;

    for (ourEnv = environ; *ourEnv; ++ourEnv)
        printf("%s\n", *ourEnv), iter++;

    return (iter > 0 ? 0 : -1);
}

#include "shell.h"

/**
 * isInputEmpty - judges if input is only space characters
 * @input: input string
 * Return: 0 if empty, -1 otherwise
 */

int isInputEmpty(char *input)
{
    int iter = 0;
    size_t spc = 0;

    if (input)
        for (iter = 0; input[iter]; iter++)
            if (input[iter] == ' ' ||
                input[iter] == '\n' ||
                input[iter] == '\t' ||
                input[iter] == '\r')
                spc++;

    return (spc == strlen(input) ? 0 : -1);
}

#include "shell.h"

/**
 * checkFileExistence - checks if a file exists
 * @file: file that needs to be checked
 * Return: The status of the requested file
 */

int checkFileExistence(char *file)
{
    struct stat buffer;

    return (stat(file, &buffer));
}

#include "shell.h"

/**
 * executeCommand - launches input command with its arguments
 * @input: command
 * @argv: arguments to the command
 */

void executeCommand(char *input, char **argv)
{
    pid_t launch = 0;
    int status = 0;

    launch = fork();

    if (launch == -1)
        perror(argv[0]), exit(EXIT_FAILURE);
    else if (launch == 0)
    {
        if (execvp(argv[0], argv) == -1)
            perror(argv[0]), free(input), exit(EXIT_FAILURE);
    }
    else
        wait(&status);
}

#include "shell.h"

/**
 * freeCommandArray - frees memory related to cmdS argv created in main
 * @cmdS: argument vector
 */

void freeCommandArray(char **cmdS)
{
    int iter = 0;

    for (iter = 0; cmdS[iter]; iter++)
        cmdS[iter] = NULL;

    if (*cmdS)
        free(*cmdS), *cmdS = NULL;
}

#include "shell.h"

/**
 * splitString - splits/tokenizes input string per delimiter(s)
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 * Return: next acceptable instance of input, NULL otherwise
 */

char *splitString(char **input, char *delim)
{
    char *cmdT = NULL;

    while ((cmdT = strsep(input, delim)) && !*cmdT)
        ;

    return (cmdT);
}

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

    for (dup = input, iter = 0; (cmdT = splitString(&dup, delim)); iter++)
    {
        cmdS[iter] = cmdT;
        if (strcmp("exit", cmdS[0]) == 0)
        {
            freeCommandArray(cmdS);
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
        signal(SIGINT, handleSignal);

        prmptChk = readPrompt("# ", &input, &inputLen);
        if (prmptChk == -1)
            free(input), exit(0);
        else if (prmptChk == 1)
            continue;

        if (isInputEmpty(input) == 0)
        {
            free(input), input = NULL;
            continue;
        }

        parseInput(input, cmdS, SPC_DELIM);

        executeCommand(input, cmdS);

        freeCommandArray(cmdS);

        if (input != NULL)
            free(input), input = NULL;

        fflush(stdout);
    }
    return (0);
}

