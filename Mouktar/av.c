#include <stdio.h>

int main(int ac, char *av[])
{
	/* Points to the second elemenit in the array*/
        char **arg = av + 1;

    while (*arg != NULL)
    {
        printf("%s\n", *arg);
	/*Increments, points to next element in the array*/
        arg++;
    }

    return 0;
}

