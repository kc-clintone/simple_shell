#include "shell.h"

/**
 * basic_shell - This function handles the basic part of the shell.
 * Return: Nada.
*/
void basic_shell(void)
{
int x, t_cmd = 0;
char **active_simple_cmd = NULL;
size_t i = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&cmd_line, &i, stdin) != -1)
{
remove_newline_character(cmd_line);
ignore_comment_str(cmd_line);
parsed_cmds = token_processor(cmd_line, ";");
for (x = 0; parsed_cmds[x] != NULL; x++)
{
active_simple_cmd = token_processor(parsed_cmds[x], " ");
if (active_simple_cmd[0] == NULL)
{
free(active_simple_cmd);
break;
}
t_cmd = parse_processed_cmds(active_simple_cmd[0]);
shell_init_func(active_simple_cmd, t_cmd);
free(active_simple_cmd);
}
free(parsed_cmds);
}
free(cmd_line);
exit(status);
}
}
