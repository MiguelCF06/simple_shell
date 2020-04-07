#include "holberton.h"
/**
 * checkLine - Function that reads the input
 * @carac: Will be a flag to identify an exit
 * Return: Will be the read line
 */
char *checkLine(ssize_t *carac)
{
	char *lineArg = NULL;
	size_t buffersize = 0;

	*carac = getline(&lineArg, &buffersize, stdin);
	return (lineArg);
}
/**
 * parseString - Function that tokenize and return the array of strings
 * @lineArg: What is read by the input
 * @separator: Separator that we want tokenize
 * Return: A pointer to pointer of chars
 */
char **parseString(char *lineArg, char *separator)
{
	char **token;
	char *str;
	int i = 0;
	int c = 0;

	c = _strlen(lineArg);
	token = malloc(sizeof(char *) * c);
	if (token == NULL)
		return (NULL);
	str = strtok(lineArg, separator);
	while (str != NULL)
	{
		token[i] = str;
		i++;
		str = strtok(NULL, separator);
	}
	token[i] = NULL;
	return (token);
}
