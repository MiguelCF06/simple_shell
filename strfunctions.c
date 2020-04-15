#include "holberton.h"

/**
 * strDup - returns pointer to new mem alloc space which contains copy
 * @strDuplic: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *strDup(char *strDuplic)
{
	char *copy;

	int len, i;

	if (strDuplic == 0)
		return (NULL);

	for (len = 0; strDuplic[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = strDuplic[i];

	return (copy);
}

/**
 * _strLen - Function that returns the length of a string.
 * @s: Char as string
 * Return: Always 0.
 */
int _strLen(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
	}
	return (x);
}

/**
 * _strCmp - Compare two strings..
 * @s1: String 1.
 * @s2: String 2.
 * Return: Always 0.
 */
int _strCmp(char *s1, char *s2)
{
	int count;

	for (count = 0; s1[count] != '\0' && s2[count] != '\0'; count++)
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
	}
	return (s1[count] - s2[count]);
}

/**
 * strConcat - Concatenate strings
 * @s1: string 1
 * @s2: string 2
 * @s3: string 3
 * Return: a pointer or NULL
 */
char *strConcat(char *s1, char *s2, char *s3)
{
	int i, j, k;
	int tam1 = 0, tam2 = 0, tam3 = 0;
	char *dest;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	tam1 = _strLen(s1);
	tam2 = _strLen(s2);

	dest = malloc((tam1 + tam2 + 1));

	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	else
	{
		for (i = 0; i < tam1; i++)
		{
			dest[i] = s1[i];
		}
		for (j = 0; j < tam2; j++)
		{
			dest[i + j] = s2[j];
		}
	}
	return (dest);
}

/**
 * printStdout - writes a string to standard output
 * @str: string to write
 * Return: Number of chars printed or -1 on failure
 */
ssize_t printStdout(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
