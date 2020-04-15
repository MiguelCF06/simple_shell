#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * struct builtins - Structure for the builtin functions of the shell
 * @name: Builtin command
 * @f: function for the builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} built_t;

/**
 * struct variables - Variables
 * @cla: command line arguments
 * @buffer: buffer of the command
 * @env: environment variable
 * @count: count of commands entered
 * @argv: arguments when shell the shell is open
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char **cla;
	char **env;
	char **argv;
	char **commands;
	char *buffer;
	size_t count;
	int status;
} vabs_st;

char *strDup(char *strDuplic);
int _strLen(char *s);
int _strCmp(char *s1, char *s2);
char *strConcat(char *s1, char *s2, char *s3);
ssize_t printStdout(char *str);
char *checkLine(ssize_t *carac);
char **parseString(char *lineArg, char *separator);
char **_realloc(char **ptr, size_t *size);
void (*checkForBuiltins(vabs_st * vars))(vabs_st * vars);
void ourExit(vabs_st *vars);
void ourEnv(vabs_st *vars);
char *findPath(char *parse, char **env);
char **makeEnv(char **env);
void freeEnv(char **env);
void p_error(char *arg1, char *arg2, int count);
void _print(char *string);
char *_itoa(int count);

#endif
