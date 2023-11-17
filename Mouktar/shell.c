#include "shell.h"


int main(int argc, char **argv, char **environ)
{
    size_t buf_size = 0;
    char *buf = NULL;
    char *token;
    char **tokens;
    int i = 0, status;
    pid_t child_pid;
    ssize_t num_chars = 0;
	(void)argc;
    while (1)
    {
        write(1, "cisfun$ ", 9);
        num_chars = getline(&buf, &buf_size, stdin);

        if (num_chars == -1)
        {
            if (feof(stdin))
            {
                _puts("Shell exiting...\n");
                break;
            }
            else
            {
                perror("getline error");
                exit(1);
            }
        }

        /*Check if the last character is a newline*/
        if (num_chars > 0 && buf[num_chars - 1] == '\n')
        {
            /*Replace the newline character with null terminator*/
            buf[num_chars - 1] = '\0';
        }

        token = strtok(buf, "\t\n ");
        tokens = malloc(sizeof(char *) * 1024);

        while (token)
        {
            tokens[i] = token;
            token = strtok(NULL, "\t\n ");
            i++;
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
            if (execve(tokens[0], tokens, environ) == -1)
		{
                	perror(argv[0]);
	    		exit(1);
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
