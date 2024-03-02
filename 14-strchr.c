#include "shell.h"
/**
 * strchr_fn - This function finds a chararacter in a string.
 * @_str: Target string.
 * @_chr: Target character.
 * Return: A ptr to _chr.
*/
char *strchr_fn(char *_str, char _chr)
{
int x = 0;

for (; _str[x] != _chr && _str[x] != '\0'; x++)
;
if (_str[x] == _chr)
{
return (_str + x);
}
else
return (NULL);
}
