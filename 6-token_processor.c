#include "shell.h"
/**
 * tk_handler - This function is the tokenizer that processes input.
 * @delim: The delimiter to be used.
 * @usr_str: The user string to be parsed.
 *Return: Array of processed words tokens.
*/

char **tk_handler(char *usr_str, char *delim)
{
char *ptk = NULL;
char **xargv = NULL;
int xdelim = 0;
char *ptr_ref = NULL;

ptk = strtok_fn(usr_str, delim,
&ptr_ref);

while (ptk != NULL)
{
xargv = _realloc(xargv, sizeof(*xargv) * xdelim,
sizeof(*xargv) * (xdelim + 1));
xargv[xdelim] = ptk;
ptk = strtok_fn(NULL, delim, &ptr_ref);
xdelim++;
}
xargv = _realloc(xargv, sizeof(*xargv) * xdelim,
sizeof(*xargv) * (xdelim + 1));
argv[xdelim] = NULL;
return (xargv);
}
