#include "shell.h"
/**
 * parser - This function identifies and parses cmds.
 * @xcmd: Target cmds.
 * Description - Utilizes lots of functions to do it's thing.
 * Return: A constant to the type of cmd.
*/
int parser(char *xcmd)
{
int x;
char *t_path = NULL;
char *sys_cmd[] = {"env", "exit", NULL};

for (x = 0; xcmd[x] != '\0'; x++)
{
if (xcmd[x] == '/')
{
return (_EXTCMD);
}
}
for (x = 0; sys_cmd[x] != NULL; x++)
{
if (_strcmp(xcmd, sys_cmd[x]) == 0)
{
return (_INTCMD);
}
}
t_path = valid_path_check(xcmd);
if (t_path != NULL)
{
free(t_path);
return (_PATH);
}
return (_BADCMD);
}
