#include "shell.h"

/**
 * my_strcat - Concatenates two strings
 * @_src:  target source
 * @_dest: target dest
 * Return: Returns memory location of new string
*/

char *my_strcat(char *_dest, char *_src)
{
int dest_len = my_strlen(_dest);
char *cnc =  NULL;
int src_len = my_strlen(_src);

cnc = malloc(sizeof(*cnc) * (dest_len + src_len + 1));
my_strcpy(_dest, cnc);
my_strcpy(_src, cnc + dest_len);
cnc[dest_len + src_len] = '\0';
return (cnc);
}

/**
 * my_strcmp - Compares length of two strings
 * @arg1: first target string
 * @arg2: second target string
 * Return: Difference in arg1 and arg2
*/

int my_strcmp(char *arg1, char *arg2)
{
int x = 0;

while (arg1[x] != '\0')
{
if (arg1[x] != arg2[x])
{
break;
}
x++;
}
return (arg1[x] - arg2[x]);
}

/**
 * my_strcspn - Calculates segment of two strings
 * @str1: target string
 * @str2: target string
 * Return: Returns char
*/

int my_strcspn(char *str1, char *str2)
{
int x;
int str_len = 0;

for (x = 0; str1[x] != '\0'; x++)
{
if (my_strchr(str2, str1[x]) != NULL)
{
break;
}
str_len++;
}
return (str_len);
}

/**
 * my_strspn - Calculates the length of a string
 * @str1: target string
 * @str2: target string
 * Return: Retuns number of bytes
*/

int my_strspn(char *str1, char *str2)
{
int found = 0;
int x = 0;

while (str1[x] != '\0')
{
if (my_strchr(str2, str1[x]) == NULL)
{
break;
}
found++;
x++;
}
return (found);
}

/**
 * my_strchr - Locates a chararacter in a
 * given string
 * @_str: Target string
 * @_chr: Target character
 * Return: Pointer to first occurence of a _chr in _str
*/

char *my_strchr(char *_str, char _chr)
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
