#include "shell.h"
/**
 * strspn_fn - This function calculates the length of a string.
 * @f_str: Target string.
 * @s_str: Target string.
 * Return: Number of bytes.
*/
int strspn_fn(char *f_str, char *s_str)
{
int result = 0, x = 0;

while (f_str[x] != '\0')
{
if (strchr_fn(s_str, f_str[x]) == NULL)
{
break;
}
result++;
x++;
}
return (result);
}
