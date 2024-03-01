#include "shell.h"
/**
 * _env - This will print the the environment of the user in session.
 * @x_cmd: A command parameter.
 * Return: Nada.
*/
void xenv(char **x_cmd __attribute__((unused)))
{
int x;

for (x = 0; environ[count] != NULL; count++)
{
custom_printf(environ[count], STDOUT_FILENO);
custom_printf("\n", STDOUT_FILENO);
}
}
