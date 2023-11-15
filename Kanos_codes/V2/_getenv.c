#include "main.h"

extern char **environ;

char *_getenv(const char *name) 
{
    // Iterate through the environment variables
    for (int i = 0; environ[i] != NULL; i++) {
        // Find the position of '=' in the current environment variable
        int equalPos = 0;
        while (environ[i][equalPos] != '=' && environ[i][equalPos] != '\0') {
            equalPos++;
        }

        // Check if the current variable matches the specified name
        if (strncmp(environ[i], name, equalPos) == 0 && name[equalPos] == '\0') {
            // Return the value part of the environment variable
            return environ[i] + equalPos + 1;
        }
    }

    // Return NULL if the environment variable is not found
    return NULL;
}
