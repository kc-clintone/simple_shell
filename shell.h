#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define min(i, j) (((i) < (j)) ? (i) : (j))

#define _PATH 3
#define _INTCMD 2
#define _EXTCMD 1
#define _BADCMD -1

extern int _stat;
extern char *_shell;
extern char **_genv;
extern char *_cli;
extern char **_pcmds;

/**
 * struct _object - This is a structure mappinh a command name to a
 * corresponding function.
 * @_command: The command name of the target command.
 * @_fn: The func pointer to the command.
*/
typedef struct _object
{
char *_command;
void (*_fn)(char **command);
} object_map;

/**===========prototypes===========*/
void start_shell(char **c_cmd, int t_cmd);
void no_comment_char(char *xin);
void _rmnl(char *string);
void basic_shell(void);
void xenv(char **x_cmd __attribute__((unused)));
void (*pointer_func(char *xcmd))(char **);
void no_comments(char *trgt);
char **tk_handler(char *usr_str, char *delim);
int parseer(char *xcmd);

#endif /*_SHELL_H_*/
