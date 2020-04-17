# Simple Shell

## Description

Simple Shell is a program that takes some commands from the keyboard and gives them to the operating system to perform.

### Install And Use It

* Clone this repo with `git clone `
* Go to the source directory using  `cd simple_shell`
* Compile all the source code files with `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
* In the current directory will be created the executable file `hsh` with the simple shell.

#### Using simple shell in Interactive mode

* Enter into the interactive mode with `./hsh` after that you will see the prompt: (>) waiting for your input.
* Enter any command that you want, for example: `ls -l` and press enter.
* See the output of your command and the prompt will rise again.
* Exit with the builtin command `exit` or with the `CTRL + D` or `CTRL + C` signals.

#### Using simple shell in Non-Interactive mode

The shell can also be run like `sh` you online need to pipe it your input and it will execute your input and print the output to the stdout, for doing that you can do for example `echo "/bin/ls -la *.c" | ./hsh`

## Files

Filename | Description
-------- | ----------
**[holberton.h](holberton.h)** | Header file with all the prototypes
**[main.c](main.c)** | Main function
**[conditionals1.c](conditionals1.c)** |
**[conditionals2.c](conditionals2.c)** |
**[argsfunctions.c](argsfunctions.c)** |
**[strfunctions.c](strfunctions.c)** | String Functions
**[findpath.c](findpath.c)** |
**[p_error.c](p_error.c)** | Prints error message
**[man_1_simple_shell](man_1_simple_shell)** | Manual page of the Simple Shell
**[README.md](README.md)** | General description of the Simple Shell
**[AUTHORS](AUTHORS)** | List of the authors of this proyect

## Functions

Function Name | Description
------------- | -----------
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
int _atoi(char *s);
int execute_cwd(vabs_t *vars);
int check_for_dir(char *str);


### Author

Miguel Angel Cipamocha Figueredo ([MiguelCF06](https://github.com/MiguelCF06)), Juan David Suarez Wilches ([juandsuarezz](https://github.com/juandsuarezz)) at [Holberton School](https://www.holbertonschool.com/)

April - 2020