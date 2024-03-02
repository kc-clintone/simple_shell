#include "shell.h"
/**
 * _realloc - This realloc function reallocates memory block.
 * @ptr: Pointer to the initial memory.
 * @i: Size of ptr.
 * @j: Size of new memory to allocate.
 * Return: Pointer to address of new memory block.
*/
void *_realloc(void *ptr, unsigned int i, unsigned int j)
{
void *tbfr;
unsigned int x;

if (ptr == NULL)
{
tbfr = malloc(j);
return (tbfr);
}
else if (j == i)
{
return (ptr);
}
else if (j == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
else
{
tbfr = malloc(j);
if (tbfr != NULL)
{
for (x = 0; x < min(i, j); x++)
{
*((char *)tbfr + x) = *((char *)ptr + x);
}
free(ptr);
return (tbfr);
}
else
return (NULL);
}
}
