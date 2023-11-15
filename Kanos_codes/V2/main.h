#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void prntstr(char *str);
char *_getcom(char *command);
char *_getenv(const char *name);
int _strlen(char *str);
char _strcpy(char *s1, char *s2);
char *strcat(char *dest, const char *src);
