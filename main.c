#include "main.h"

/**
 * main - a simple command line interpreter
 *
 * @ac: number of args passed
 * @av: argus passed
 * Returned: 0 on success
 */
int main(int ac, shar *argv)
{
	char *line;
	size_t n, ln;

	while (1)
	{
		n = 0;
		line = malloc(n);
		printf("prompt>_ ");
		getline(&line, &n, stdin);
		fflush(stdin);

		free(line);
	}
	return (0);
}
