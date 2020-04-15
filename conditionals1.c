#include "holberton.h"
/**
 * checkForBuiltins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*checkForBuiltins(vabs_t * vars))(vabs_t * vars)
{
	unsigned int i;
	built_t check[] = {
		{"exit", ourExit},
		{"env", ourEnv},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmpr(vars->cla[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(vars);
	return (check[i].f);
}

/**
 * ourExit - exit program
 * @vars: variables
 * Return: void
 */
void ourExit(vabs_t *vars)
{
	int status;

	if (_strcmpr(vars->cla[0], "exit") == 0 && vars->cla[1] != NULL)
	{
		status = _atoi(vars->cla[1]);
		if (status == -1)
		{
			vars->status = 2;
			print_error(vars, ": Illegal number: ");
			_puts2(vars->cla[1]);
			_puts2("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}
	free(vars->buffer);
	free(vars->cla);
	free(vars->commands);
	free_env(vars->env);
	exit(vars->status);
}

/**
 * ourEnv - prints the current environment
 * @vars: struct of variables
 * Return: void.
 */
void ourEnv(vabs_st *vars)
{
	unsigned int i;

	for (i = 0; vars->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	vars->status = 0;
}
