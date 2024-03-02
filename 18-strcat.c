#include "shell.h"
/**
 * strcat_fn - This function concatenates two strings.
 * @src:  Target string to be concated.
 * @dest: Target dest of concated string.
 * Return: Memory location of new string.
*/
char *strcat_fn(char *dest, char *src)
{
int fdst = strlen_fn(dest);
int fsrc = strlen_fn(src);
char *ctd =  NULL;

ctd = malloc(sizeof(*ctd) * (fdst + fsrc + 1));
strcpy_fn(dest, ctd);
strcpy_fn(src, ctd + fdst);
ctd[fdst + fsrc] = '\0';
return (ctd);
}
