#include "shell.h"
/**
 * strcspn-fn - This function calculates parts of f_str that has
 * chars not in s_str.
 * @f_str: Target string.
 * @s_str: Target string.
 * Return: The char from f_str in s_str.
*/
int strcspn_fn(char *f_str, char *s_str)
{
int _len = 0, x;

for (x = 0; f_str[x] != '\0'; x++)
{
if (strchr_fn(s_str, f_str[x]) != NULL)
break;
_len++;
}
return (_len);
}
