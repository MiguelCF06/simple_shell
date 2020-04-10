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
	int count = 1;

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
					p_error(argv[0], parse[0], count);
					free(pathF);
					free(parse);
					if (fd == 0)
						exit(2);
					return (1);
				}
			}
		}
		else
			checkWexit(statusPid, fd);
		count++;
	}
	return (0);
}
