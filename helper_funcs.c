#include "shell.h"

/**
 * execute_parsed_command - This function executes the parsed cmd
 * @arg1: Parsed form of the input command
 * @arg2: The type of target command
 * Return: Returns nothing
*/

void execute_parsed_command(char **arg1, int arg2)
{
void (*function)(char **my_cmd);

if (arg2 == EXT_CMD)
{
if (execve(arg1[0], arg1, NULL) == -1)
{
perror(get_sys_env("PWD"));
exit(2);
}
}
if (arg2 == MY_PATH)
{
if (execve(path_checker(arg1[0]), arg1, NULL) == -1)
{
perror(get_sys_env("PWD"));
exit(2);
}
}
if (arg2 == INT_CMD)
{
function = fnptr(arg1[0]);
function(arg1);
}
if (arg2 == BAD_CMD)
{
my_printf(shell_prompt, STDERR_FILENO);
my_printf(": 1: ", STDERR_FILENO);
my_printf(arg1[0], STDERR_FILENO);
my_printf(": command not found\n", STDERR_FILENO);
shell_status = 127;
}
}

/**
 * parse_commands - This function identifies processed command
 * @cmds: Target command
 * Description - Makes use of certain commands defined in shell.h
 * Return: Returns a constant represrnting
 * the type of the command
*/

int parse_commands(char *cmds)
{
int index;
char *temporary_path = NULL;
char *built_in_commands[] = {"env", "exit", NULL};

for (index = 0; cmds[index] != '\0'; index++)
{
if (cmds[index] == '/')
{
return (EXT_CMD);
}
}
for (index = 0; built_in_commands[index] != NULL; index++)
{
if (my_strcmp(cmds, built_in_commands[index]) == 0)
{
return (INT_CMD);
}
}
temporary_path = path_checker(cmds);
if (temporary_path != NULL)
{
free(temporary_path);
return (MY_PATH);
}
return (BAD_CMD);
}

/**
 * path_checker - This function checks if a valid command is
 * present in the PATH env present
 * @my_cmd: The target command
 * Return: Returns the valid path of the command
 *         NULL if otherwise.
*/

char *path_checker(char *my_cmd)
{
char *sec, *tmpcp, *pri;
char *actual_path = get_sys_env("PATH");
char **patht = NULL;
int index;

if (actual_path == NULL || my_strlen(actual_path) == 0)
{
return (NULL);
}
tmpcp = malloc(sizeof(*tmpcp) * (my_strlen(actual_path) + 1));
my_strcpy(actual_path, tmpcp);
patht = my_processor(tmpcp, ":");
for (index = 0; patht[index] != NULL; index++)
{
sec = my_strcat(patht[index], "/");
pri = my_strcat(sec, my_cmd);
if (access(pri, F_OK) == 0)
{
free(sec);
free(patht);
free(tmpcp);
return (pri);
}
free(pri);
free(sec);
}
free(tmpcp);
free(patht);
return (NULL);
}

/**
 * fnptr - This function will retrieve a function
 * @my_cmd: Target string
 * Return: Returns a pointer to the actual function
 *         Null on failure
*/

void (*fnptr(char *my_cmd))(char **)
{
int i;

objMapper mapTo[] = {
{"env", env}, {"exit", my_exit}
};

for (i = 0; i < 2; i++)
{
if (my_strcmp(my_cmd, mapTo[i]._cmd_) == 0)
return (mapTo[i].function);
}
return (NULL);
}

/**
 * get_sys_env - This function retrieves the value of an env variable
 * @arg1: Name of the env
 * Return: Returns the value of a variable
*/

char *get_sys_env(char *arg1)
{
char *arg1_copy;
char *k;
char **temp_env;

for (temp_env = environ; *temp_env != NULL; temp_env++)
{
for (k = *temp_env, arg1_copy = arg1;
*k == *arg1_copy; k++, arg1_copy++)
{
if (*k == '=')
{
break;
}
}
if ((*k == '=') && (*arg1_copy == '\0'))
return (k + 1);
}
return (NULL);
}
