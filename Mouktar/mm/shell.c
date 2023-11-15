#include "hsh.h"


int main()
{
	char *line;
	char **args;
	int s = 1, status;

	while (s || status)
	{
		_puts("cisfun$ ");
		line = read_line();
		args = split_line(line);
		status = execute(args);
		free(line);
		free(args);
		s = 0;
	}
}
