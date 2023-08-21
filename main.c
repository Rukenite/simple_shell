#include "main.h"

/**
 * main - a simple command line interpreter
 *
 * @ac: number of args passed
 * @av: argus passed
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	char *line, **command;
	size_t n, ln;

	while (1)
	{
		n = 0;
		line = malloc(n);
		printf("prompt>_ ");
		getline(&line, &n, stdin);
		fflush(stdin);
		printf("%s", line);
		command = _strtok(line);
		_execve(command);

		_free(command);
	}
	_free(command);
	return (0);
}
