#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM " \t\r\n\a"

char **bmsh_split_line(char *line)
{
	int no_tokens = 1;
	char *lineptr_copy;
	lineptr_copy = malloc(sizeof(char) * line);

	if (lineptr_copy== NULL)
	{
		perror("bmsh: memory allocation error");
		return (-1);
	}

	strcpy(lineptr_copy, line);

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		no_tokens++;
		token = strtok(NULL, delim);
        }
	char **tokens = malloc(no_tokens * sizeof(char*));
	token = strtok(lineptr_copy, DELIM);
	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		token = strtok(NULL, delim);
	}
	tokens[index] = NULL; 
	
	return tokens;
}


