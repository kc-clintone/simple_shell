#include "shell.h"
/**
 * strtok_fn - This function tokenizes an input.
 * @ref_pointer: Keeps track of tokens.
 * @_delim: Stores delimiter to be used while parsing.
 * @_str: Target string to be parsed.
 * Return: Next available token in line.
*/
char *strtok_fn(char *_str, char *_delim, char **ref_pointer)
{
char *halt;

if (_str == NULL)
{
_str = *ref_pointer;
}
if (*_str == '\0')
{
*ref_pointer = _str;
return (NULL);
}
_str += strspn_fn(_str, _delim);
if (*_str == '\0')
{
*ref_pointer = _str;
return (NULL);
}
halt = _str + strcspn_fn(_str, _delim);
if (*halt == '\0')
{
*ref_pointer = halt;
return (_str);
}
*halt = '\0';
*ref_pointer = halt + 1;
return (_str);
}
