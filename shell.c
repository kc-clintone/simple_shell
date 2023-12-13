#include "shell.h"
/**
 * displayPrompt - Display the shell prompt
 */
void prompt(void)
{
printf("$ ");
}
/**
* main - the entry point of the shell program
* @argc: the number of arguments passed to main function
* @argv: the program arguments to be parsed to main function
* Return: 0 on success, 1 otherwise
*/
int main(void)
{
pid_t pid = fork();
ssize_t x = 0;
int status;
char *usr_input = NULL;
size_t input_len = 0;

while(1)
{
prompt();

x = getline(&usr_input, &input_len, stdin) != -1;

if (x == -1)
{
printf("\n");
break;
}
usr_input[strcspn(usr_input, "\n")] = '\0';

if (pid == -1)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(usr_input, usr_input, (char *)NULL);
}
if (pid == -1)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(usr_input, usr_input, (char *)NULL);
perror("Command not found");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
fprintf(stderr, "Error: Command exited with status %d\n", WEXITSTATUS(status));
}
}
}
free(usr_input);
return (0);
}
