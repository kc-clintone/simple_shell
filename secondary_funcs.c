#include "shell.h"

/**
 * discard_comments - This ignores anything after '#' char
 * @i: User input
 * Return: Returns nothing
*/

void discard_comments(char *i)
{
int k = 0;

if (i[k] == '#')
{
i[k] = '\0';
}
while (i[k] != '\0')
{
if (i[k] == '#' && i[k - 1] == ' ')
break;
k++;
}
i[k] = '\0';
}


/**
 * my_realloc - A custom malloc function
 * @ptr: Pointer to the memory
 * @c_size: Current size of ptr
 * @r_size: Size of new memory
 * Return: Pointer to the address of new memory block
*/

void *my_realloc(void *ptr, unsigned int c_size,
unsigned int r_size)
{
void *tmp_bfr;
unsigned int i;

if (ptr == NULL)
{
tmp_bfr = malloc(r_size);
return (tmp_bfr);
}
else if (r_size == c_size)
{
return (ptr);
}
else if (r_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
else
{
tmp_bfr = malloc(r_size);
if (tmp_bfr != NULL)
{
for (i = 0; i < min(c_size, r_size); i++)
{
*((char *)tmp_bfr + i) = *((char *)ptr + i);
}
free(ptr);
return (tmp_bfr);
}
else
return (NULL);
}
}


/**
 * my_strtok - This function tokenizes an input string
 * @refptr: Keeps track of teckens
 * @del: Stores delimiter for parsing
 * @str: Target string
 * Return: Returns the next available token in line
*/
char *my_strtok(char *str, char *del, char **refptr)
{
char *halt;

if (str == NULL)
{
str = *refptr;
}
if (*str == '\0')
{
*refptr = str;
return (NULL);
}
str += my_strspn(str, del);
if (*str == '\0')
{
*refptr = str;
return (NULL);
}
halt = str + my_strcspn(str, del);
if (*halt == '\0')
{
*refptr = halt;
return (str);
}
*halt = '\0';
*refptr = halt + 1;
return (str);
}

/**
 * my_atoi - This functions casts string to int
 * @str: Target string
 * Return: Returns the converted string
 */
int my_atoi(char *str)
{
unsigned int k = 0;

do {
if (*str == '-')
{
return (-1);
}
else if ((*str < '0' || *str > '9') && *str != '\0')
{
return (-1);
}
else if (*str >= '0'  && *str <= '9')
{
k = (k * 10) + (*str - '0');
}
else if (k > 0)
{
break;
}
} while (*str++);
return (k);
}

/**
 * discard_comment_str - This removes/ignores strings after
 * the a '#' character
 * @ui: User's input
 * Return: Returns nothing
*/

void discard_comment_str(char *ui)
{
int k = 0;

if (ui[k] == '#')
{
ui[k] = '\0';
}
while (ui[k] != '\0')
{
if (ui[k] == '#' && ui[k - 1] == ' ')
{
break;
}
k++;
}
ui[k] = '\0';
}
