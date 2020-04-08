#include "holberton.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: Argument vector contains the arguments passed to the program
 * @env: Environment variable
 * Return: Always 0 (Success) and exit
 */
int main(int argc, char *argv[], char **env)
{
	pid_t child;
	int fd = 0, cmp = 0, statusPid = 0, i = 0;
	char *lineArg, *pathF;
	ssize_t carac;
	char **parse;

	while (1)
	{
		child = fork();
		checkChild(child);
		fd = isatty(STDIN_FILENO);
		if (child == 0)
		{
			if (argc == 1)
			{
				checkConditionalFd(fd);
				lineArg = checkLine(&carac);
				checkConditionalCaracLine(carac, lineArg);
				parse = parseString(lineArg, " \n\t\r");
				cmp = _strCmp(parse[0], "env");
				checkCmp(cmp, env, i);
				cmp = _strCmp(parse[0], "exit");
				checkIfExit(parse, lineArg, cmp);
				pathF = findPath(parse[0], env);
				if (execve(pathF, parse, NULL) == -1)
				{
					free(pathF);
					free(parse);
					perror(argv[0]);
					if (fd == 0)
						exit(2);
				}
			}
		}
		else
		{
			checkWexit(statusPid, fd);
		}
	}
	return (0);
}
