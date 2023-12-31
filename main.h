#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAXSIZE 500

int _execve(char **command, char *sh, int n, char **env, int *st);
int handle_builtins(char **builtin, char **environ);
char **_strtok(char *lineread);
void _free(char **buff);
char *_stat(char *cmd);
#endif

