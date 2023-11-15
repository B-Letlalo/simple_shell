#include "main.h"

char *strcat(char *dest, const char *src) {
    // Find the null terminator of the destination string
    char *ptr = dest;
    while (*ptr != '\0') {
        ptr++;
    }

    // Copy the source string to the end of the destination string
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }

    // Append null terminator to the concatenated string
    *ptr = '\0';

    // Return the modified destination string
    return dest;
}
