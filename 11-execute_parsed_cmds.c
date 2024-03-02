#include "shell.h"
/**
 * exepcmd - This function executes the parsed/processed commands.
 * @x_cmd: The parsed form of the input command.
 * @t_cmd: Type of the command.
 * Return: Nada.
*/
void exepcmd(char **x_cmd, int t_cmd)
{
void (*_fn)(char **command);

if (t_cmd == _EXTCMD)
{
if (execve(x_cmd[0], x_cmd, NULL) == -1)
{
perror(sys_getenv("PWD"));
exit(2);
}
}
if (t_cmd == _PATH)
{
if (execve(valid_path_check(x_cmd[0]),
x_cmd, NULL) == -1)
{
perror(sys_getenv("PWD"));
exit(2);
}
}
if (t_cmd == _INTCMD)
{
_fn = pointer_func(x_cmd[0]);
_fn(x_cmd);
}
if (t_cmd == _BADCMD)
{
_stdout(_shell, STDERR_FILENO);
_stdout(": 1: ", STDERR_FILENO);
_stdout(x_cmd[0], STDERR_FILENO);
_stdout(": not found\n", STDERR_FILENO);
_stat = 127;
}
}
