#include "main.h"

#include <stdio.h>

extern char **environ;

int main(void)
{
    /* Iterate through the environment variables using environ*/
    for (int i = 0; environ[i] != NULL; i++)
    {
        prntstr(environ[i]);
    }

    return 0;
}

