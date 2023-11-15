#include "main.h"

/**
 * _strlen - returns length of a string
 * Return: length of the string
 * @str: string input
 */

int _strlen(char *str)
{
	int i;
	i = 0;

	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}
