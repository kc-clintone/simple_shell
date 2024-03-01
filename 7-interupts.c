#include "shell.h"

/**
 * _control_c - This simple fn handles interupt for the
 * CTRL+C signal.
 * @sgn: The signal value.
 * Return: Nada.
*/
void _control_c(int sgn)
{
if (sgn == SIGINT)
{
custom_printf("\n$ ", STDIN_FILENO);
}
}
