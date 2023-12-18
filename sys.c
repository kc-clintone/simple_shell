#include "shell.h"

/**
 * quit - .another way to exit the shell
 * @simpleCommand: any command entered
 * Return: nothing to return here
 */
void quit(char **simpleCommand)
{
int args, tkx = 0;

for (; simpleCommand[tkx] != NULL; tkx++);

if (tkx == 1)
{
free(simpleCommand);
free(commandLine);
free(parsedCommands);
exit(status);
}
else if (tkx == 2)
{
args = stringToIntConverter(simpleCommand[1]);
if (args == -1)
{
_printf(shell_prompt, STDERR_FILENO);
_printf(": 1: exit: Illegal number: ", STDERR_FILENO);
_printf(simpleCommand[1], STDERR_FILENO);
_printf("\n", STDERR_FILENO);
status = 2;
}
else
{
free(commandLine);
free(simpleCommand);
free(parsedCommands);
exit(args);
}
}
else
_printf("$: too many arguments\n", STDERR_FILENO);
}

/**
 * _env - prints the the environment of the
 * current user in session
 * @simple_cmd: a simple command parameter
 * Return: nothing to return here
 */
void env(char **simple_cmd __attribute__((unused)))
{
int count;

for (count = 0; environ[count] != NULL; count++)
{
custom_printf(environ[count], STDOUT_FILENO);
custom_printf("\n", STDOUT_FILENO);
}
}
