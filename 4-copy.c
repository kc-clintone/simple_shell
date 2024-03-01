#include "shell.h"

/**
 * strcpy_fn - This function copies a string to a buffer.
 * @source: Target string.
 * @dest: the destination to copy to
 * Return: Returns nothing
*/

void strcpy_fn(char *source, char *dest)
{
int x = 0;

for (; source[x] != '\0'; x++)
{
dest[x] = source[x];
}
dest[x] = '\0';
}
