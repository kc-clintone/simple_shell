#include "shell.h"
/**
 * pointer_func - This function retrieves a function.
 * @xcmd: The target string.
 * Return: A pointer to the actual function, otherwise Null.
*/
void (*pointer_func(char *xcmd))(char **)
{
int x;
object_map map_func_to[] = {
{"env", env}, {"exit", quit}
};

for (x = 0; x < 2; x++)
{
if (_strcmp(xcmd, map_func_to[x]._command) == 0)
return (map_func_to[x]._fn);
}
return (NULL);
}
