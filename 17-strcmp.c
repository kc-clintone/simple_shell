#include "shell.h"
/**
 * strcmp_fn - This function compares length of two strings.
 * @f_str: Target string.
 * @s_str: Target string.
 * Return: length.
*/
int strcmp_fn(char *f_str, char *s_str)
{
int x = 0;

while (f_str[x] != '\0')
{
if (f_str[x] != s_str[x])
{
break;
}
x++;
}
return (f_str[x] - s_str[x]);
}
