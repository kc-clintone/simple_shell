#include "shell.h"

/**
 * my_printf - This function prints a string to stdout
 * @str: Target string
 * @stream: Stream input
 * Return: Returns nothing
*/

void my_printf(char *str, int stream)
{
int i = 0;

for (; str[i] != '\0'; i++)
{
write(stream, &str[i], 1);
}
}

/**
 * null_char - Removes new line character from a string
 * @str: string parameter
 *Return: Returns nothing
*/

void null_char(char *str)
{
int c = 0;

while (str[c] != '\0')
{
if (str[c] == '\n')
{
break;
}
c++;
}
str[c] = '\0';
}

/**
 * my_processor - Tokenizer function to process input and
 * stores it into an array
 * @del: The delimiter to be used
 * @ui: The user input
 * Return: Array of processed tokens
*/

char **my_processor(char *ui, char *del)
{
int cd = 0;
char *ptr_ref = NULL;
char *ptoken = NULL;
char **my_argv = NULL;

ptoken = my_strtok(ui, del, &ptr_ref);

while (ptoken != NULL)
{
my_argv = my_realloc(my_argv, sizeof(*my_argv) * cd,
sizeof(*my_argv) * (cd + 1));
my_argv[cd] = ptoken;
ptoken = my_strtok(NULL, del, &ptr_ref);
cd++;
}
my_argv = my_realloc(my_argv, sizeof(*my_argv) * cd,
sizeof(*my_argv) * (cd + 1));
my_argv[cd] = NULL;
return (my_argv);
}

/**
 * my_strcpy - Copies a string to another buffer
 * @_src: the source
 * @_dest: the destination
 * Return: Returns nothing
*/

void my_strcpy(char *_src, char *_dest)
{
int x = 0;

for (; _src[x] != '\0'; x++)
{
_dest[x] = _src[x];
}
_dest[x] = '\0';
}

/**
 * my_strlen - counts string length
 * @str: string to be counted
 * Return: length of the string
*/

int my_strlen(char *str)
{
int len = 0;

if (str == NULL)
{
return (len);
}
for (; str[len] != '\0'; len++)
{
	;
}
return (len);
}
