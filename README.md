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
**[holberton.h](holberton.h)** |
**[main.c](main.c)** | Main function
**[conditionals1.c](conditionals1.c)** |
**[conditionals2.c](conditionals2.c)** |
**[argsfunctions.c](argsfunctions.c)** |
**[strfunctions.c](strfunctions.c)** |
**[findpath.c](findpath.c)** |
**[p_error.c](p_error.c)** |
**[man_1_simple_shell](man_1_simple_shell)** |
**[README.md](README.md)** | General description of the Simple Shell
**[AUTHORS](AUTHORS)** |

