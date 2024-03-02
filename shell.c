#include "shell.h"
/**
* main - Entry point of the shell program.
* @argc: Number of args passed to main function.
* @argv: Program args parsed to main function.
* Return: 0 on success, 1 on fail.
*/
int main(int argc __attribute__((unused)), char **argv)
{
char **x_cmd = NULL;
size_t xv = 0;
int x, t_cmd = 0;

signal(SIGINT, _control_c);
signal(SIGQUIT, _control_d);
_shell = argv[0];
while (1)
{
basic_shell();
_stdout("$ ", STDOUT_FILENO);
if (getline(&_cli, &xv, stdin) == -1)
{
free(_cli);
exit(_stat);
}
_rmnl(_cli);
no_comments(_cli);
_pcmds = tk_handler(_cli, ";");

for (x = 0; _pcmds[x] != NULL; x++)
{
x_cmd = tk_handler(_pcmds[x], " ");
if (x_cmd[0] == NULL)
{
free(x_cmd);
break;
}
t_cmd = _pcmds(x_cmd[0]);
start_shell(x_cmd, t_cmd);
free(x_cmd);
}
free(_pcmds);
}
free(_cli);
return (_stat);
}
