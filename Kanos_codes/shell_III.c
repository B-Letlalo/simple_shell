#include "main.h"

#define MAX_TOKENS 1024

int main(void)
{
    size_t buf_size = 0;
    char *buf = NULL;
    char *token;
    char *tokens[MAX_TOKENS];
    int i = 0, status;
    pid_t child_pid;

    while (1)
    {
        write(1, "cisfun$ ", 9);
        ssize_t num_chars = getline(&buf, &buf_size, stdin);

        if (num_chars == -1)
        {
            if (feof(stdin))
            {
                printf("Shell exiting...\n");
                break;
            }
            else
            {
                perror("getline error");
                exit(1);
            }
        }

        if (num_chars > 0 && buf[num_chars - 1] == '\n')
        {
            buf[num_chars - 1] = '\0';
        }

        token = strtok(buf, "\t\n ");
        i = 0;

        while (token)
        {
            tokens[i++] = token;
            token = strtok(NULL, "\t\n ");
        }

        tokens[i] = NULL;

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork error");
            return 1;
        }

        if (child_pid == 0)
        {
            /* Search for the executable in the PATH*/
            char *path = getenv("PATH");
            char *path_copy = strdup(path);
            char *dir = strtok(path_copy, ":");
            char exec_path[1024];

            while (dir)
            {
                snprintf(exec_path, sizeof(exec_path), "%s/%s", dir, tokens[0]);
                execve(exec_path, tokens, NULL);
                dir = strtok(NULL, ":");
            }

            /* If execve fails, print an error*/
            perror(tokens[0]);
            free(path_copy);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }

    }

    free(buf);
    return 0;
}

