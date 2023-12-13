#include "shell.h"

/**
 * _printf - prints a string to stdout
 * @str: target string to be printed
 * @input: user input
 * @strm: streams input to printf to print out
 * Return: Returns void/nothing
*/

void _printf(char *input, int strm)
{
	int i = 0;

for (; input[i] != '\0'; i++)
{
write(strm, &input[i], 1);
}
}
