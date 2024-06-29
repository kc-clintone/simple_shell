#include "shell.h"
//----------global variables---------
char *command_line; /*for command line*/
char **pcmds; /*for parsed cmd*/
char *shell_prompt; /*my shell prompt*/
int shell_status; /*program status*/
//-----------------------------------


/**
 * main - Entry point to shell program
 * @argc_arr: Number of args passed to main function
 * @argv_arr: Program args to be parsed to main function
 * Return: 0 on success,
 *         1 otherwise
*/

int main(int myargc __attribute__((unused)), char **myargv)
{
int index, cmd_type = 0;
char **active_cmd = NULL;
size_t count = 0;

signal(SIGINT, my_ctrlc);
signal(SIGQUIT, my_ctrld);
shell_prompt = myargv[0];
while (1)
{
normal();
my_printf("$ ", STDOUT_FILENO);
if (getline(&command_line, &count, stdin) == -1)
{
free(command_line);
exit(shell_status);
}
null_char(command_line);
discard_comments(command_line);
pcmds = my_processor(command_line, ";");

for (index = 0; pcmds[index] != NULL; index++)
{
active_cmd = my_processor(pcmds[index], " ");
if (active_cmd[0] == NULL)
{
free(active_cmd);
break;
}
cmd_type = parse_commands(active_cmd[0]);
start_shell(active_cmd, cmd_type);
free(active_cmd);
}
free(pcmds);
}
free(command_line);
return (shell_status);
}


/**
 * my_ctrld - Handles signal interupt => CTRL-D
 * @sgn: Signal value (number)
 * Return: returns nothing
*/

void my_ctrld(int sgn)
{
if (sgn == SIGQUIT)
{
printf("\n");
exit(0);
}
}
