#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void prntstr(char *str);
char *_getcom(char *command);
char *_getenv(const char *name);
