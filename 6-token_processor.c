#include "shell.h"
/**
 * tk_handler - This function is the tokenizer that processes input.
 * @delim: The delimiter to be used.
 * @usr_str: The user string to be parsed.
 *Return: Array of processed words tokens.
*/

char **tk_handler(char *usr_str, char *delim)
{
int count_delimiter = 0;
char *pointer_ref = NULL;
char *processed_token = NULL;
char **_argv = NULL;

processed_token = cutomized_strtok_for_shell(usr_input_string, delimiter,
&pointer_ref);

while (processed_token != NULL)
{
_argv = custom_realloc(_argv, sizeof(*_argv) * count_delimiter,
sizeof(*_argv) * (count_delimiter + 1));
_argv[count_delimiter] = processed_token;
processed_token = cutomized_strtok_for_shell(NULL, delimiter, &pointer_ref);
count_delimiter++;
}
_argv = custom_realloc(_argv, sizeof(*_argv) * count_delimiter,
sizeof(*_argv) * (count_delimiter + 1));
_argv[count_delimiter] = NULL;
return (_argv);
}
