# Simple Shell

## Description

Simple Shell is a program that takes some commands from the keyboard and gives them to the operating system to perform.

### Install And Use It

* Clone this repo with `git clone `
* Go to the source directory using  `cd simple_shell`  
* Compile all the source code files with `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
* In the current directory will be created the executable file `hsh` with the simple shell.

#### Using simple shell in Interactive mode

* Enter into the interactive mode with `./hsh`  after that you will see the prompt: (>) waiting for your input. 
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
**[conditionals1.c](conditionals1.c)** | Prints the prompt
**[conditionals2.c](conditionals2.c)** | Checks the input
**[argsfunctions.c](argsfunctions.c)** | Reads and tokenize
**[strfunctions.c](strfunctions.c)** | String Functions
**[findpath.c](findpath.c)** | Valid commands
**[p_error.c](p_error.c)** | Prints error message
**[man_1_simple_shell](man_1_simple_shell)** | Manual page of the Simple Shell
**[README.md](README.md)** | General description of the Simple Shell
**[AUTHORS](AUTHORS)** | List of the authors of this proyect

## Functions

Function Name | Description
------------- | -----------
_strLen | Returns the length of a string
_strCmp | Compare two strings
strConcat | Concatenate strings
checkLine | Reads the input
parseString | Tokenize and return a array of strings
findPath | Check if the value is in the PATH
_getenv | Get the path from a env
checkChild | Check if the forking of child is good
checkConditionalFd | Check if the fd is not 0
checkConditionalCaracLine | Check the ssize_t carac and line is EOF or \n
checkCmp | Check if the compare is 0 and write
checkIfExit | Check if the command exit is in the prompt
checkWexit | Check the status of the pid is correct and wait for it, and exit
p_error | Prints error if the command is not found
_print | Prints strings
_itoa | Converts a int to a string

### Author

Miguel Angel Cipamocha Figueredo ([MiguelCF06](https://github.com/MiguelCF06)), Juan David Suarez Wilches ([juandsuarezz](https://github.com/juandsuarezz)) at [Holberton School](https://www.holbertonschool.com/)

April - 2020