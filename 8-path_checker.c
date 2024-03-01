#include "shell.h"
/**
* valid_path_check - This function checks if a valid command is
* in the present PATH.
* @x_cmd: the command to be parsed.
* Return: Returns the valid path of the command, NULL if otherwise
*/
char *check_for_valid_path(char *cmd)
{
char *secondary, *temp_copy, *primary;
char *the_actual_path = sys_getenv("PATH");
char **path_tray = NULL;
int indexer;

if (the_actual_path == NULL || _strlen(the_actual_path) == 0)
{
return (NULL);
}
temp_copy = malloc(sizeof(*temp_copy) * (_strlen(the_actual_path) + 1));
_strcpy(the_actual_path, temp_copy);
path_tray = token_processor(temp_copy, ":");
for (indexer = 0; path_tray[indexer] != NULL; indexer++)
{
secondary = _strcat(path_tray[indexer], "/");
primary = _strcat(secondary, cmd);
if (access(primary, F_OK) == 0)
{
free(secondary);
free(path_tray);
free(temp_copy);
return (primary);
}
free(primary);
free(secondary);
}
free(temp_copy);
free(path_tray);
return (NULL);
}
