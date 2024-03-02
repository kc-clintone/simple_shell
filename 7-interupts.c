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
_stdout("\n$ ", STDIN_FILENO);
}

/**
 * _control_d - This simple fn handles interupt for the
 * CTRL+D signal.
 * @sgn: The signal value.
 * Return: Nada.
*/
void _control_d(int sgn)
{
if (sgn == SIGQUIT)
{
printf("\n");
exit(0);
}
}
