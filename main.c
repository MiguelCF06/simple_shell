#include "holberton.h"

int main(int argc, char *argv[], char **env)
{
	pid_t child;
	int fd = 0;
	int cmp = 0;
	char *lineArg;
	char *pathF;
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
					write(1,"> ", 2);
				}
				lineArg = checkLine(&carac);
				if (carac == EOF)
				{
					free(lineArg);
					write(1,"\n", 2);
					exit(3);
				}
				if (lineArg == "\n")
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
						write(1, *env[i], _strLen(*env[i]));
						write(1, "\n", 2);
						i++;
					}
				}
				pathF = findPath(parse[0], *env); 
			}
		}
	}
}
