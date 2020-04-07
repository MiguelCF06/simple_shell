#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int _strLen(char *s);
int _strCmp(char *s1, char *s2);
char *strConcat(char *s1, char *s2, char *s3);
char *checkLine(ssize_t *carac);
char **parseString(char *lineArg, char *separator);
char *findPath(char *parse, char **env);
char *_getenv(char *envname, char **env);

#endif
