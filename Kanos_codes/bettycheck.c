#include "main.h"

/**
 * main - does something
 * Return: 0
 */

int main(void)
{
	int i = rand();

	printf("%d\n");

	if (i < 1000)
		printf("number over 1000");
	else
		printf("number not over a 1000");
	return	(0);
}
