#include "shell.h"

/* global vars */
char *shell_prompt;
char **parsedCommands;
char *commandLine;
int status = 0;

/**
 * control_d - this is a helper function that  handles
 * the "CTRL + D"signal
 * @signal: signal value (mosttly a number)
 * Return: it usually returns nothing
*/

void control_d(int _signal)
{
if (_signal == SIGQUIT)
{
printf("\n");
exit(0);
}
}

/**
 * main - this is the main function, the entry point to
 * the shell program
 * @argc: this is an array of number of arguments passed to the main
 * function during execution
 * @argv: this is an array of  program arguments to be parsed to
 * the main function
 * Return: 0 upon success, 1 otherwise
*/

int main(int argc __attribute__((unused)), char **argv)
{
size_t c = 0;
char **currentSimpleCmd = NULL;
int i, typeOfSimpleCmd = 0;

signal(SIGINT, control_c);
signal(SIGQUIT, control_d);
shell_prompt = argv[0];
while (1)
{
nonInteractive();
_printf("$ ", STDOUT_FILENO);
if (getline(&commandLine, &c, stdin) == -1)
{
free(commandLine);
exit(status);
}
rmNewline(commandLine);
handleComments(commandLine);
parsedCommands = tokenHandler(commandLine, ";");

for (i = 0; parsedCommands[i] != NULL; i++)
{
currentSimpleCmd = tokenHandler(parsedCommands[i], " ");
if (currentSimpleCmd[0] == NULL)
{
free(currentSimpleCmd);
break;
}
typeOfSimpleCmd = parseCommands(currentSimpleCmd[0]);
startShell(currentSimpleCmd, typeOfSimpleCmd);
free(currentSimpleCmd);
}
free(parsedCommands);
}
free(commandLine);
return (status);
}
