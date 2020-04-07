#include "holberton.h"

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
	if (s3 == NULL)
		s3 = "";
	tam1 = _strLen(s1);
	tam2 = _strLen(s2);
	tam3 = _strLen(s3);

	dest = malloc((tam1 + tam2 + tam3 + 1));

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
		for (k = 0; k <= tam3; k++)
		{
			dest[i + j + k] = s3[k];
		}
	}
	return (dest);
}
