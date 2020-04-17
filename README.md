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
**[conditionals1.c](conditionals1.c)** | Exit and env functions
**[conditionals2.c](conditionals2.c)** | Make and free the env
**[argsfunctions.c](argsfunctions.c)** | Tokenize
**[strfunctions.c](strfunctions.c)** | String Functions
**[findpath.c](findpath.c)** | Execute commands in the path
**[p_error.c](p_error.c)** | Prints error message
**[man_1_simple_shell](man_1_simple_shell)** | Manual page of the Simple Shell
**[README.md](README.md)** | General description of the Simple Shell
**[AUTHORS](AUTHORS)** | List of the authors of this proyect

## Functions

Function Name | Description
------------- | -----------
strDup | Returns a pointer to new memory allocation Space
_strLen | Returns the length of a string
_strCmp | Compare two strings
strConcat | Concatenate two strings
printStdout | Writes a string to standar output
parseString | Tokenize and returns an array of strings
_realloc | Reallocate a pointer to double the space
checkForBuiltins | Check if a command is a builtin
ourExit | Exit the program
ourEnv | Prints the current environment
find_path | Find a PATH Variable
path_execute | Executes a command in the path
check_for_path | Chacks if the command is in the PATH
makeEnv | Make the shell env from the env passed to main
freeEnv | Free the env of the shell
p_error | Prints the error messages
_print | Prints a string
_itoa | Converts an integer to a string
_atoi | Converts a string to an integer
execute_cwd | Executes a command in the current directory
check_for_dir | Check if the command is a part of a path

### Documentation

Display the manual with the following command:
`man ./man_1_simple_shell` 

### Authors

* Miguel Angel Cipamocha Figueredo ([MiguelCF06](https://github.com/MiguelCF06))
* Juan David Suarez Wilches ([juandsuarezz](https://github.com/juandsuarezz))

At [Holberton School](https://www.holbertonschool.com/)

April - 2020