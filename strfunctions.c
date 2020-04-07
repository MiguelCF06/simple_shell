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
 * strConcat - Concatenates a string.
 * @s1: String 1
 * @s2: String 2
 * Return: Null or the array concatenate.
 */
char *strConcat(char *s1, char *s2)
{
	int con1 = 0;
	int con2 = 0;
	char *conar;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[con1] != '\0')
		con1++;
	while (s2[con2] != '\0')
		con2++;

	conar = malloc(sizeof(char) * (con1) + (con2 + 1));

	if (conar == NULL)
	{
		return (NULL);
	}
	for (con1 = 0; s1[con1] != '\0'; con1++)
	{
		conar[con1] = s1[con1];
	}
	for (con2 = 0; s2[con2] != '\0'; con1++, con2++)
	{
		conar[con1] = s2[con2];
	}
	conar[con1] = '\0';
	return (conar);
}
