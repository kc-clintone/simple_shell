#include "shell.h"

/**
 * basic_shell - This function handles the basic part of the shell.
 * Return: Nada.
*/
void basic_shell(void)
{
int x, t_cmd = 0;
char **x_cmd = NULL;
size_t i = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&_cli, &i, stdin) != -1)
{
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
t_cmd = parser(x_cmd[0]);
start_shell(x_cmd, t_cmd);
free(x_cmd);
}
free(_pcmds);
}
free(_cli);
exit(_stat);
}
}
