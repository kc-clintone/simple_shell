#include "shell.h"

/**
* nonInteractive - this is a function that handles the
* non_interactive part of the shell
* Return: returns nothing
*/

void nonInteractive(void)
{
char **currentSimpleCmd = NULL;
size_t count = 0;
int i, typeOfSimpleCmd = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&commandLine, &count, stdin) != -1)
{
rmNewline(commandLine);
handleComments(commandLine);
parsedCommands = tokenHandler(commandLine, ";");
for (i = 0; parsedCommands[i] != NULL; i++)
{
currentSimpleCmd = tokenHandler(parsedCommands[i], " ");
if (currentSimpleCmd[0] == NULL)
{
free(currentSimpleCmd);
break;
}
typeOfSimpleCmd = parseCommands(currentSimpleCmd[0]);
startShell(currentSimpleCmd, typeOfSimpleCmd);
free(currentSimpleCmd);
}
free(parsedCommands);
}
free(commandLine);
exit(status);
}
}


/**
 * handleComments - this func ignores anything after '#' char
 * @input: user's input
 * Return: Returns nothing
*/

void handleComments(char *input)
{
int i = 0;

if (input[i] == '#')
{
input[i] = '\0';
}
while (input[i] != '\0')
{
if (input[i] == '#' && input[i - 1] == ' ')
break;
i++;
}
input[i] = '\0';
}


/**
 * handleDeleteComments - this func remove anything after
 * '#' char
 * @usrIn: user's input
 * Return: Returns nothing
*/

void handleDeleteComments(char *usrIn)
{
int i = 0;

if (usrIn[i] == '#')
{
usrIn[i] = '\0';
}
while (usrIn[i] != '\0')
{
if (usrIn[i] == '#' && usrIn[i - 1] == ' ')
break;
i++;
}
usrIn[i] = '\0';
}


/**
 * control_c - this functions handles the signal interupt
 * => CTRL-C
 * @_signal: signal value
 * Return: returns nothing
*/
void control_c(int _signal)
{
if (_signal == SIGINT)
{
_printf("\n$ ", STDIN_FILENO);
}
}
