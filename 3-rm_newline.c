#include "shell.h"

/**
 * _rmnl - Removes new line character from a string.
 * @string: String param.
 *Return: Nada.
*/

void _rmnl(char *string)
{
int x = 0;

while (string[x] != '\0')
{
if (string[x] == '\n')
{
break;
}
x++;
}
string[x] = '\0';
}
