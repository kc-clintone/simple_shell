#include "shell.h"

/**
 * startShell - this function starts the shell program
 * @typeOfSimpleCmd: target token/cmd to parse
 * @currentSimpleCmd: attempts to get and process current/initial token
 * Return: Returns nothing
*/
void startShell(char **currentSimpleCmd, int typeOfSimpleCmd)
{
pid_t runningPid;

if (typeOfSimpleCmd, == HANDLE_EXT_CMD || typeOfSimpleCmd, == HANDLE_PATH)
{
runningPid = fork();
if (runningPid == 0)
{
exec_parsed_cmd(currentSimpleCmd, typeOfSimpleCmd);
}
else
{
waitpid(runningPid, &status, 0);
status >>= 8;
}
}
else
{
exec_parsed_cmd(currentSimpleCmd, typeOfSimpleCmd);
}


