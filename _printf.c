#include <stdio.h>
/**
 * _printf - Mimics printf
 * @format: First operand
 *
 * Return: no_char_printed as count;
 */
int _printf(const char *format, ...)
{
	int n;

	n = printf(format, ...);
	
	return(n);
}	
