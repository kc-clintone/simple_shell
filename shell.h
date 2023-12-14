#ifndef SHELL_H
#define SHELL_H

/** some important headers **/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>

/** function prototypes **/
void _printf(char *input, int strm);
void quit(char **simpleCommand);
void handleComments(char *input);
void handleDeleteComments(char *usrIn);
void *reallocator(void *pointer, unsigned int initialSize,
unsigned int reallocatedSize);
void *reallocator(void *pointer, unsigned int initialSize,
unsigned int reallocatedSize);

int stringToIntConverter(char *);

char *shellTokenizer(char *targetString, char *delimiter, char **pointer);

#endif /* SHELL_H */
