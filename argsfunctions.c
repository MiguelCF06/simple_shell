#include "holberton.h"
/**
 * parseString - Function that tokenize and return the array of strings
 * @buffer: What is read by the input, and will tokenize
 * @separator: Separator that we want tokenize
 * Return: A pointer to pointer of chars
 */
char **parseString(char *buffer, char *separator)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = new_strtok(buffer, separator)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = _realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
