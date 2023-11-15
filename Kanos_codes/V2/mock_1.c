#include "main.h"

// Function declarations
void concatenateString(char *destination, const char *source);
void copyString(char *destination, const char *source);

int main(void)
{
    size_t buf_size = 0;
    char *buf = NULL;
    char *token;
    char **tokens;
    int i = 0, status;
    pid_t child_pid;
    ssize_t num_chars = 0;

    while (1)
    {
        write(1, "#cisfun$ ", 9);
        num_chars = getline(&buf, &buf_size, stdin);

        if (num_chars == -1)
        {
            write(1, "Shell exiting...\n", 17);
            break;
        }

        /* Check if the last character is a newline */
        if (num_chars > 0 && buf[num_chars - 1] == '\n')
        {
            /* Replace the newline character with a null terminator */
            buf[num_chars - 1] = '\0';
        }

        token = strtok(buf, " \t");  // Remove '\n' from delimiters

        tokens = malloc(sizeof(char *) * 2); // Allocate space for the command and NULL terminator

        while (token)
        {
            tokens[i] = token;
            token = strtok(NULL, " \t");
            i++;
        }
        tokens[i] = NULL;

        // Specify the full path to the executable
        char path[1024];
        copyString(path, "/bin/");
        concatenateString(path, tokens[0]);

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork error");
            return 1;
        }
        if (child_pid == 0)
        {
            // Execute the command
            if (execve(path, tokens, NULL) == -1)
            {
                perror("execve error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }

        i = 0;
        free(tokens);
    }

    free(buf);
    return 0;
}

// Function to concatenate two strings
void concatenateString(char *destination, const char *source)
{
    while (*destination)
    {
        destination++;
    }
    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

// Function to copy a string
void copyString(char *destination, const char *source)
{
    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

