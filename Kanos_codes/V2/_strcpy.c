#include "main.h"

/**
 * _strcpy - copies string pointed to by s2
 * Return: s1(copied string)
 * @s1: destination string
 * @s2: string to be copied
 */

char _strcpy(char *s1, char *s2)
{
	int i;
	i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}
