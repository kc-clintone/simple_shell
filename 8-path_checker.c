#include "shell.h"
/**
 * valid_path_check - This function checks if a valid command is
 * in the present PATH.
 * @xcmd: The target command.
 * Return: The valid path of the c.d, NULL otherwise.
*/
char *valid_path_check(char *xcmd)
{
int x;
char **pthtr = NULL;
char *_sec, *tcopy, *_pri;
char *t_path = sys_getenv("PATH");

if (t_path == NULL || strlen_fn(t_path) == 0)
{
return (NULL);
}
tcopy = malloc(sizeof(*tcopy) * (strlen_fn(t_path) + 1));
_strcpy(t_path, tcopy);
pthtr = tk_handler(tcopy, ":");
for (x = 0; pthtr[x] != NULL; x++)
{
_sec = _strcat(pthtr[x], "/");
_pri = _strcat(_sec, xcmd);
if (access(_pri, F_OK) == 0)
{
free(_sec);
free(pthtr);
free(tcopy);
return (_pri);
}
free(_pri);
free(_sec);
}
free(tcopy);
free(pthr);
return (NULL);
}
