#include "main.h"

// Function to tokenize the input buffer
char** tokenizeInput(char *input) {
    char *token;
    char **tokens = malloc(sizeof(char *) * 1024);
    int i = 0;

    token = strtok(input, "\t\n ");
    
    while (token) {
        tokens[i] = token;
        token = strtok(NULL, "\t\n ");
        i++;
    }

    tokens[i] = NULL;

    return tokens;
}

// Function to execute a command with fork and wait
void executeCommand(char **tokens) {
    int status;
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork error");
        exit(1);
    }

    if (child_pid == 0) {
        if (execve(tokens[0], tokens, NULL) == -1)
            perror("./shell ");
    } else {
        wait(&status);
    }
}

int main(void) {
    size_t buf_size = 0;
    char *buf = NULL, **tokens;
    ssize_t num_chars = 0;

    while (1) {
        write(1, "cisfun$ ", 9);
        num_chars = getline(&buf, &buf_size, stdin);

        if (num_chars == -1) {
            write(1, "Shell Exiting...\n", 17);
            free(buf);
            return (-1);
        }

        if (num_chars > 0 && buf[num_chars - 1] == '\n') {
            buf[num_chars - 1] = '\0';
        }

        tokens = tokenizeInput(buf);
        executeCommand(tokens);

        free(tokens);

        free(buf);
    }

    return 0;
}
