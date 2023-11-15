#include "main.h"

/**
 * _prntstr - prints string
 * @str: pointer to string that will be printed
 */

void _prntstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
