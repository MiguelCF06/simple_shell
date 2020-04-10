#include "holberton.h"
/**
 * p_error - prints error if the command is not found
 * @arg1: name of the executable file
 * @arg2: name of the command that not exists
 * @count: number of proccess
**/

void p_error(char *arg1, char *arg2, int count)
{
	char *numstr;

	_print(arg1);
	_print(": ");
	numstr = _itoa(count);
	_print(numstr);
	_print(": ");
	_print(arg2);
	_print(": ");
	write(STDERR_FILENO, "not found\n", 11);
}
/**
 * _print - prints strings
 * @string: string that we can print
 **/

void _print(char *string)
{
	int num = 0, len = 0;

	num = _strLen(string);
	len = write(STDERR_FILENO, string, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}
}
/**
 * _itoa - converts a int to a string
 * @count: int that will convert in a string
 * Return: string converted
 **/

char *_itoa(int count)
{
	char *str;
	unsigned int temp, num;

	temp = count;
	for (num = 0; temp != 0; num++)
		temp /= 10;
	str = malloc(sizeof(char) * (num + 1));
	if (str == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	str[num] = '\0';
	for (--num; count; --num)
	{
		str[num] = (count % 10) + '0';
		count /= 10;
	}
	return (str);
}
