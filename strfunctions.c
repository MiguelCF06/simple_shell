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

	for (count = 0; s1[count] == s2[count]; count++)
	{
		if (s1[count] == '\0')
			return (0);
	}
	return (s1[count] - s2[count]);
}

/**
 * strConcat - Concatenate strings
 * @s1: string 1
 * @s2: string 2
 * Return: a pointer or NULL
 */
char *strConcat(char *s1, char *s2)
{
	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (s1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; s1[len1]; len1++)
			;
	}
	if (s2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; s2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstring[i] = s1[i];
	newstring[i] = '/';
	for (j = 0; j < len2; j++)
		newstring[i + 1 + j] = s2[j];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}

/**
 * printStdout - writes a string to standard output
 * @str: string to write
 * Return: Number of chars printed or -1 on failure
 */
ssize_t printStdout(char *str)
{
	ssize_t num, len;

	num = _strLen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
