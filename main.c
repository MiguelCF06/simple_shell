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
	char *lineArg, pathF;
	ssize_t carac;
	char **parse;

	while (true)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error: forking child");
			return (-1);
		}
		fd = isatty(STDIN_FILENO);
		if (child == 0)
		{
			if (argc == 1)
			{
				if (fd != 0)
				{
					write(1, "> ", 2);
				}
				lineArg = checkLine(&carac);
				if (carac == EOF)
				{
					free(lineArg);
					write(1, "\n", 2);
					exit(3);
				}
				if (*lineArg == '\n')
				{
					free(lineArg);
					return (0);
				}
				parse = parseString(lineArg, " \n\t\r");
				cmp = _strCmp(parse[0], "env");
				if (cmp == 0)
				{
					while (*env[i] != NULL)
					{
						write(1, env[i], _strLen(env[i]));
						write(1, "\n", 2);
						i++;
					}
				}
				cmp = _strCmp(parse[0], "exit");
				if (cmp == 0 && parse[1] == NULL)
				{
					free(parse);
					free(lineArg);
					exit(3);
				}
				pathF = findPath(parse[0], env);
				if (execve(pathF, parse, NULL) == -1)
				{
					free(pathF);
					free(parse);
					perror(argv[0]);
					if (fd == 0)
						exit(2);
					return (1);
				}
			}
		}
		else
		{
			wait(&statusPid);
			statusPid = WEXITSTATUS(statusPid);
			if (statusPid == 2)
				exit(127); /* exit for command not found in the path */
			if (fd == 0 || statusPid == 3)
				break;
		}
	}
	return (0);
}
