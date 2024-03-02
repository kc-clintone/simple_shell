#include "shell.h"

char **_genv;

/**
 * xenv - This will print the the environment of the user in session.
 * @x_cmd: A command parameter.
 * Return: Nada.
*/
void xenv(char **x_cmd __attribute__((unused)))
{
int x;

for (x = 0; _genv[x] != NULL; x++)
{
_stdout(_genv[x], STDOUT_FILENO);
_stdout("\n", STDOUT_FILENO);
}
}
