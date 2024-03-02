#include "shell.h"
/**
 * start_shell - This function initializes/starts and executes shs.
 * @t_cmd: Target token/cmd.
 * @c_cmd: This attempts to process current token/cmd.
 * Return: Nada.
*/
void start_shell(char **c_cmd, int t_cmd)
{
pid_t current_pid;

if (t_cmd == _EXTCMD || t_cmd == _PATH)
{
current_pid = fork();
if (current_pid == 0)
{
exepcmd(c_cmd, t_cmd);
}
else
{
waitpid(current_pid, &_stat, 0);
_stat >>= 8;
}
}
else
{
exepcmd(c_cmd, t_cmd);
}
}
