#include "holberton.h"
/**
* findPath - Function that check if the value is in the PATH
* @parse: The char previously read by the input
* @env: The environ
* Return: A concatenated string with the new path or cont if it fails
**/
char *findPath(char *parse, char **env)
{
	char *line;
	char *carac = "/";
	char *newpath = NULL;
	char **token = NULL;
	int compare = 1;
	int i = 0;

	line = _getenv("PATH", env);
	token = parseString(line, ":");
	while (token[i])
	{
		newpath = strConcat(token[i], carac, parse);
		compare = access(newpath, X_OK);
		if (compare == 0)
		{
			return (newpath);
		}
		else
		{
			free(newpath);
			i++;
		}
	}
	free(token);
	return (parse);
}
/**
 * _getenv - Function that will get the path from a env
 * @envname: The name from the env like "PATH"
 * @env: Take the environ
 * Return: A char * with the path
 */
char *_getenv(char *envname, char **env)
{
	char **token;
	int i = 0;

	i = 0;
	while (env[i] != NULL)
	{
		token = parseString(*(env + i), "=");
		if (_strCmp(token[0], envname) == 0)
		{
			break;
		}
		free(token);
		i++;
	}
	return (token[1]);
}
