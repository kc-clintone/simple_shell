#include "shell.h"
/**
 * no_comments - This function removes/ignores after the a '#'.
 * @trgt: Target input.
 * Return: Nada.
*/
void no_comment(char *trgt)
{
int x = 0;

if (trgt[x] == '#')
{
trgt[x] = '\0';
}
while (trgt[x] != '\0')
{
if (trgt[x] == '#' && trgt[x - 1] == ' ')
{
break;
}
x++;
}
trgt[x] = '\0';
}
