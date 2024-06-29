#include "shell.h"

/**
 * start_shell - This function will initialize & executes
 * almost everything
 * @cmd_type: Target token type
 * @current_cmd: Gets and processes current token
 * Return: Returns nothing
*/

void start_shell(char **current_cmd, int cmd_type)
{
pid_t active_ID;

if (cmd_type == EXT_CMD || cmd_type == MY_PATH)
{
active_ID = fork();
if (active_ID == 0)
{
execute_parsed_command(current_cmd, cmd_type);
}
else
{
waitpid(active_ID, &shell_status, 0);
shell_status >>= 8;
}
}
else
{
execute_parsed_command(current_cmd, cmd_type);
}
}
