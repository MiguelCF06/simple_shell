#include "holberton.h"
/**
 *checkChild - Check if the forking of child is good
 *@child: The child process
 *
 */
void checkChild(pid_t child)
{
	if (child == -1)
	{
		perror("Error: forking child");
	}
}
/**
 *checkConditionalFd - Check if the fd is not 0
 *@fd: The file descriptor
 *
 */
void checkConditionalFd(int fd)
{
	if (fd != 0)
		write(1, "> ", 2);
}
/**
 *checkConditionalCaracLine - Check the ssize_t carac and line is EOF or \n
 *@carac: The direction of the char in the input
 *@lineArg: The input
 */
void checkConditionalCaracLine(ssize_t carac, char *lineArg)
{
	if (carac == EOF)
	{
		free(lineArg);
		write(1, "\n", 2);
		exit(3);
	}
	if (*lineArg == '\n')
	{
		free(lineArg);
	}
}
