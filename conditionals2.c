#include "holberton.h"
/**
 *checkCmp - Check if the compare is 0 and write
 *@cmp: The compare value
 *@env: Environment variable
 *@i: iterator
 */
void checkCmp(int cmp, char **env, int i)
{
	if (cmp == 0)
	{
		while (env[i] != NULL)
		{
			write(1, env[i], _strLen(env[i]));
			write(1, "\n", 1);
			i++;
		}
	}
}
/**
 *checkIfExit - Check if the command exit is in the prompt
 *@parse: The string parsed
 *@lineArg: The input
 *@cmp: Value of the compare
 */
void checkIfExit(char **parse, char *lineArg, int cmp)
{
	if (cmp == 0 && parse[1] == NULL)
	{
		free(parse);
		free(lineArg);
		exit(3);
	}
}
/**
 *checkWexit - Check the status of the pid is correct and wait for it, and exit
 *@statusPid: The status of the process id
 *@fd: File descriptor
 */
void checkWexit(int statusPid, int fd)
{
	wait(&statusPid);
	statusPid = WEXITSTATUS(statusPid);
	if (statusPid == 2)
		exit(127); /* exit for command not found in the path */
	if (fd == 0 || statusPid == 3)
		exit(3);
}
