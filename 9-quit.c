#include "shell.h"
/**
 * quit - This will force-exits the shell.
 * @x_cmd: Executed command.
 * Return: Nada.
 */
void quit(char **x_cmd)
{
int xargs, tc = 0;

for (; x_cmd[tc] != NULL; tc++)
;
if (tc == 1)
{
free(x_cmd);
/*----TODO: Doublecheck here----*/
free(_cli);
free(_pcmds);
exit(_stat);
}
else if (tc == 2)
{
xargs = custom_atoi(x_cmd[1]);
if (xargs == -1)
{
_stdout(prompt, STDERR_FILENO);
custom_printf(": 1: exit: Illegal number: ", STDERR_FILENO);
custom_printf(simple_cmd[1], STDERR_FILENO);
custom_printf("\n", STDERR_FILENO);
status = 2;
}
else
{
free(cmd_line);
free(simple_cmd);
free(parsed_cmds);
exit(args);
}
}
else
custom_printf("$: too many arguments\n", STDERR_FILENO);
}
