#include "shell.h"

/**
 * my_exit - This function exits/quits the prompt
 * @my_cmd: A simple command parameter
 * Return: Nothing
*/

void my_exit(char **my_cmd)
{
int args;
int count = 0;

for (; my_cmd[count] != NULL; count++)
	;
if (count == 1)
{
free(my_cmd);
free(command_line);
free(pcmds);
exit(shell_status);
}
else if (count == 2)
{
args = my_atoi(my_cmd[1]);
if (args == -1)
{
my_printf(shell_prompt, STDERR_FILENO);
my_printf(": 1: exit: Invalid number: ", STDERR_FILENO);
my_printf(my_cmd[1], STDERR_FILENO);
my_printf("\n", STDERR_FILENO);
shell_status = 2;
}
else
{
free(command_line);
free(my_cmd);
free(pcmds);
exit(args);
}
}
else
my_printf("$: too many arguments\n", STDERR_FILENO);
}

/**
 * env - This prints the the environment of the
 * current user in session
 * @my_cmd: a simple command parameter
 * Return: Nothing
*/

void env(char **my_cmd __attribute__((unused)))
{
int counter;

for (counter = 0; environ[counter] != NULL; counter++)
{
my_printf(environ[counter], STDOUT_FILENO);
my_printf("\n", STDOUT_FILENO);
}
}
