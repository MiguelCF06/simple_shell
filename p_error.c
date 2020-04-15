#include "holberton.h"
/**
 * p_error - prints error messages
 * @vars: struct of variables
 * @errormsg: number of proccess
**/

void p_error(vabs_t *vars, char *errormsg)
{
	char *numstr;

	_print(vars->argv[0]);
	_print(": ");
	numstr = _itoa(vars->count);
	_print(numstr);
	_print(": ");
	_print(vars->cla[0]);
	if (errormsg)
	{
		_print(errormsg);
	}
	else
		perror("");
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
