#include "main.h"
int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	char **tokens;
	int i = 0, status;
	pid_t child_pid;
	
	while (1)
	{
		write (1, "cisfun$ ", 9);
		getline (&buf, &buf_size, stdin);
		token = strtok(buf, "\t\n ");
		tokens = malloc (sizeof(char *) * 1024);
		
		while (token)
		{
			tokens[i] = token;
			token = strtok (NULL, "\t\n ");
			i++;
		}
		tokens[i] = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork error");
			return(1);
		}
		if (child_pid == 0)
		{
			if(execve(tokens[0], tokens, NULL) == -1)
				perror("error with exec");
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(tokens);
	}
	return (0);
}
