#include "shell.h"
/**
 * strlen_fn - This function counts length of the target string.
 * @string: Target string.
 * Return: Length of the target string.
*/
int strlen_fn(char *string)
{
int ln = 0;

if (string == NULL)
{
return (ln);
}
for (; string[ln] != '\0'; ln++)
{
;
}
return (ln);
}
