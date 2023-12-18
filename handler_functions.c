#include "shell.h"

/**
 * reallocator - this is a custom realloc function that reallocates a memory block
 * @pointer: pointer to the memory previously allocated with a call to malloc
 * @initialSize: size of the pointer initially
 * @reallocatedSize: size of the new memory to be allocated
 * Return: pointer to the address of the new memory block
 */
void *reallocator(void *pointer, unsigned int initialSize,
unsigned int reallocatedSize)
{
void *_buffer;
unsigned int i;

if (pointer == NULL)
{
_buffer = malloc(reallocatedSize);
return (_buffer);
}
else if (reallocatedSize == initialSize)
{
return (pointer);
}
else if (reallocatedSize == 0 && pointer != NULL)
{
free(pointer);
return (NULL);
}
else
{
_buffer = malloc(reallocatedSize);
if (_buffer != NULL)
{
for (i = 0; i < min(initialSize, reallocatedSize); i++)
{
*((char *)_buffer + i) = *((char *)pointer + i);
}
free(pointer);
return (_buffer);
}
else
return (NULL);
}
}

/**
 * stringToIntConverter - this function casts string to integer
 * @targetString: target string to be casted
 * Return: Returns the converted string
 */
int stringToIntConverter(char *targetString)
{
unsigned int x = 0;

do {
if (*targetString == '-')
{
return (-1);
}
else if ((*targetString < '0' || *targetString > '9') &&
*targetString != '\0')
{
return (-1);
}
else if (*targetString >= '0' && *targetString <= '9')
{
x = (x * 10) + (*targetString - '0');
}
else if (x > 0)
{
break;
}
} while (*targetString++);
return (x);
}

/**
 * shellTokenizer - this function tries to
 * tokenizes an input string
 * @pointer: this pointer keeps track of tokens
 * @delimiter: stores delimiter to be used while parsing
 * the string
 * @targetString: target string to be parsed into a command
 * Return: Returns the next available token in line if exists
*/
char *shellTokenizer(char *targetString, char *delimiter, char **pointer)
{
char *interruptSignal;

if (targetString == NULL)
{
targetString = *pointer;
}
if (*targetString == '\0')
{
*pointer = targetString;
return (NULL);
}
targetString += _strspn(targetString, delimiter);
if (*targetString == '\0')
{
*pointer = targetString;
return (NULL);
}
interruptSignal = targetString + _strcspn(targetString, delimiter);
if (*interruptSignal == '\0')
{
*pointer = interruptSignal;
return (targetString);
}
*interruptSignal = '\0';
*pointer = interruptSignal + 1;
return (targetString);
}
