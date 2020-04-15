#include "holberton.h"

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
	if (!isatty(STDIN_FILENO))
		pipe = 1;
	if (pipe == 0)
		write(1, "> ", 2);
	while (getline(&(vars.buffer), &lenBuffer, stdin) != -1)
	{
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
