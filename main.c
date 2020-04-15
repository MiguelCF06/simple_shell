#include "holberton.h"

unsigned int signalFlag;

/**
 * sigHandler - handles ^C signal interupt
 * @unusedVar: unused variable (required for signal function prototype)
 * Return: void
 */
static void sigHandler(int unusedVar)
{
	(void) unusedVar;
	if (signalFlag == 0)
		printStdout("\n> ");
	else
		printStdout("\n");
}

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t lenBuffer = 0;
	unsigned int pipe = 0, i;
	vabs_st vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;
	vars.env = make_env(environment);
	signal(SIGINT, sigHandler);
	if (!isatty(STDIN_FILENO))
		pipe = 1;
	if (pipe == 0)
		write(1, "> ", 2);
	signalFlag = 0;
	while (getline(&(vars.buffer), &lenBuffer, stdin) != -1)
	{
		signalFlag = 1;
		vars.count++;
		vars.commands = parseString(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.cla = tokenize(vars.commands[i], "\n \t\r");
			if (vars.cla && vars.cla[0])
				if (check_for_builtins(&vars) == NULL)
					check_for_path(&vars);
			free(vars.cla);
		}
		free(vars.buffer);
		free(vars.commands);
		signalFlag = 0;
		if (pipe == 0)
			write(1, "> ", 2);
		vars.buffer = NULL;
	}
	if (pipe == 0)
		printStdout("\n");
	freeEnv(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
