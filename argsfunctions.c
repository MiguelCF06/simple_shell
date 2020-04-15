#include "holberton.h"
/**
 * parseString - Function that tokenize and return the array of strings
 * @buffer: buffer what we want tokenize
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
	while ((tokens[i] = strtok(buffer, separator)) != NULL)
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

/**
 * _atoi - string to integer
 * @s: string to transform
 * Return: integer
 */
int _atoi(char *s)
{
	int n;
	int sign = 1;
	unsigned int res = 0;

	for (n = 0; *(s + n) != '\0'; n++)
	{
		if (*(s + n) == '-')
			sign *= -1;
		if (*(s + n) >= '0' && *(s + n) <= '9')
			res = res * 10 + (*(s + n) - '0');
		else if (res > 0)
			break;
	}
	return (res * sign);
}
