#include "holberton.h"
/**
 * path_execute - executes a command in the path
 * @command: path to the command
 * @vars: struct of variables
 * Return: 0 if succcess, 1 if failure
 */
int path_execute(char *command, vabs_st *vars)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			p_error(vars, NULL);
		if (child_pid == 0)
		{
			if (execve(command, vars->cla, vars->cla) == -1)
				p_error(vars, NULL);
		}
		else
		{
			wait(&vars->status);
			if (WIFEXITED(vars->status))
				vars->status = WEXITSTATUS(vars->status);
			else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
				vars->status = 130;
			return (0);
		}
		vars->status = 127;
		return (1);
	}
	else
	{
		p_error(vars, ": Permission denied\n");
		vars->status = 126;
	}
	return (0);
}

/**
 * find_path - find a PATH variable
 * @env: environment variables
 * Return: pointer to the node that contains the PATH, or NULL on failure
 */
char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);

}

/**
 * check_for_path - checks if the command is in the PATH
 * @vars: variables
 */
void check_for_path(vabs_st *vars)
{
	char *path, *path_dup = NULL, *check = NULL;
	unsigned int i = 0, r = 0;
	char **path_tokens;
	struct stat buf;

	if (check_for_dir(vars->cla[0]))
		r = execute_cwd(vars);
	else
	{
		path = find_path(vars->env);
		if (path != NULL)
		{
			path_dup = _strdup(path + 5);
			path_tokens = parseString(path_dup, ":");
			for (i = 0; path_tokens && path_tokens[i]; i++, free(check))
			{
				check = _strcat(path_tokens[i], vars->cla[0]);
				if (stat(check, &buf) == 0)
				{
					r = path_execute(check, vars);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (path_tokens == NULL)
			{
				vars->status = 127;

