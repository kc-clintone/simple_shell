#ifndef _SHELL_H
#define _SHELL_H

/** Including headers **/
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/** External variables**/
extern char **environ; /*for environmrnt variable*/
extern char *command_line; /*for command line*/
extern char **pcmds; /*for parsed cmd*/
extern char *shell_prompt; /*my shell prompt*/
extern int shell_status; /*program status*/

/** Function prototypes **/
void my_printf(char *, int);
void null_char(char *);
int my_strlen(char *);
char *my_strtok(char *, char *, char **);
char **my_processor(char *, char *);
void my_exit(char **my_cmd);
void env(char **);
char *my_strcat(char *, char *);
char *my_strchr(char *, char);
int my_strspn(char *, char *);
void my_strcpy(char *, char *);
int my_strcmp(char *, char *);
int my_atoi(char *);
int my_strcspn(char *, char *);
void my_ctrlc(int);
void execute_parsed_command(char **, int);
void my_ctrld(int);
void discard_comments(char *);
int parse_commands(char *);
char *path_checker(char *);
void (*fnptr(char *))(char **);
char *get_sys_env(char *);
extern void normal(void);
void start_shell(char **current_cmd, int cmd_type);
void *my_realloc(void *ptr, unsigned int c_size,
unsigned int r_size);

/**Others*/
#define min(i, j) (((i) < (j)) ? (i) : (j))

/**
 * struct obj - Thus struct that maps cmd name to
 * a corresponding function
 * @_cmd_: Name of the command
 * @function: Function pointer to the command
*/
typedef struct obj
{
	char *_cmd_;
	void (*function)(char **my_cmd);
} objMapper;

/** Program constants **/
#define INT_CMD 2
#define EXT_CMD 1
#define MY_PATH 3
#define BAD_CMD -1

#endif /*_SHELL_H*/
