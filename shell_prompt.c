#include "shell.h"

/**
* normal - This function handles non_interactive shell
* Return: Returns nothing
*/

void normal(void)
{
size_t k = 0;
char **current_cmd = NULL;
int i;
int cmd_type = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&command_line, &k, stdin) != -1)
{
null_char(command_line);
discard_comments(command_line);
pcmds = my_processor(command_line, ";");
for (i = 0; pcmds[i] != NULL; i++)
{
current_cmd = my_processor(pcmds[i], " ");
if (current_cmd[0] == NULL)
{
free(current_cmd);
break;
}
cmd_type = parse_commands(current_cmd[0]);
start_shell(current_cmd, cmd_type);
free(current_cmd);
}
free(pcmds);
}
free(command_line);
exit(shell_status);
}
}

/**
 * my_ctrlc - Handles signal interupt => CTRL-C
 * @sgn: signal value
 * Return: returns nothing
*/

void my_ctrlc(int sgn)
{
if (sgn == SIGINT)
{
my_printf("\n", STDIN_FILENO);
}
}
