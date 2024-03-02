#include "shell.h"
/**
 * no_comments - This function removes/ignores after the a '#'.
 * @trgt: Target input.
 * Return: Nada.
*/
void no_comments(char *trgt)
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

/**
 * no_comment_char - This functiin ignores anything after '#' char.
 * @xin: User input.
 * Return: Nada.
*/
void no_comment_char(char *xin)
{
int x = 0;

if (xin[x] == '#')
{
xin[x] = '\0';
}
while (xin[x] != '\0')
{
if (xin[x] == '#' && xin[x - 1] == ' ')
break;
x++;
}
xin[x] = '\0';
}
