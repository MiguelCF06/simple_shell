#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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
} vabs_t;

/**
 * struct builtins - Structure for the builtin functions of the shell
 * @name: Builtin command
 * @f: function for the builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vabs_t *);
} built_t;

char *strDup(char *strDuplic);
int _strLen(char *s);
int _strCmp(char *s1, char *s2);
char *strConcat(char *s1, char *s2);
ssize_t printStdout(char *str);
char **parseString(char *buffer, char *separator);
char **_realloc(char **ptr, size_t *size);
void (*checkForBuiltins(vabs_t *vars))(vabs_t *vars);
void ourExit(vabs_t *vars);
void ourEnv(vabs_t *vars);
char *find_path(char **env);
int path_execute(char *command, vabs_t *vars);
void check_for_path(vabs_t *vars);
char **makeEnv(char **env);
void freeEnv(char **env);
void p_error(vabs_t *vars, char *errormsg);
void _print(char *string);
char *_itoa(int count);

#endif
