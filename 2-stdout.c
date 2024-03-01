#include "shell.h"

/**
 * _stdout - prints a string to stdout.
 * @str: Target string to be printed.
 * @strm: Streams input to printf.
 * Return: Nada.
*/

void _stdout(char *str, int strm)
{
int x = 0;

for (; str[x] != '\0'; x++)
{
write(strm, &str[x], 1);
}
}
