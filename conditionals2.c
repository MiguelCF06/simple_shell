#include "holberton.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **newMem;
	size_t i;

	newMem = malloc(sizeof(char *) * ((*size) + 10));
	if (newMem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		newMem[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new);
}

/**
 * makeEnv - make the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **makeEnv(char **env)
{
	char **newEnv = NULL;
	sise_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newEnv = malloc(sizeof(char *) * i + 1);
	if (newEnv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
	{
		newEnv[i] = strDup(env[i]);
	}
	newEnv[i] = NULL;
	return (newEnv);
}

/**
 * freeEnv - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void freeEnv(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
