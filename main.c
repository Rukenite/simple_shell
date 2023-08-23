#include "main.h"

/**
 * main - a simple command line interpreter
 *
 * @ac: number of args passed
 * @av: argus passed
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char *av[])
{
	char *line, **command;
	size_t n, ln = 0;

	while (1)
	{
		n = 0;
		printf("prompt>_ ");
		line = malloc(n);
		getline(&line, &n, stdin);
		if (feof(stdin))
		{
			free(line);
			putchar('\n');
			break;
		}
		fflush(stdin);
		ln++;
		if (*line == '\n')
		{
			free(line);
			continue;
		}
		command = _strtok(line);
		if (!command)
			continue;
		_execve(command, av[0], ln);
		_free(command);
	}
	return (0);
}

