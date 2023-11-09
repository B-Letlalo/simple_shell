#include <stdio.h>
#include <stdlib.h>

char *bmsh_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;

	chars_read = getline(&line, &bufsize, stdin);

	if (chars_read == -1)
	{
		perror("bmsh: getline error");
	}


	return line;
}

int main()
{
	printf("$ ");
	fflush(stdout);

    // Read the user's command
	char *input_line = bmsh_read_line();

	if (input_line == NULL)
	{
		printf("No input received.\n");
	}
	else
	{
        // Print the user's command
		printf("%s", input_line);

        // Free the allocated memory
		free(input_line);
	}

    return 0;
}
