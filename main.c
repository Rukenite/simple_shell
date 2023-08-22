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
	size_t n = 1, ln = 1;

	while (1)
	{
		n = 0;
		line = malloc(n);
		printf("prompt>_ ");
		getline(&line, &n, stdin);
		fflush(stdin);
		if (feof(stdin))
		{
			free(line);
			putchar('\n');
			return (0);
		}
		command = _strtok(line);
		if (!command)
		{
			_free(command);
			continue;
		}
		_execve(command, av[0], ln);
		_free(command);
		ln++;
	}
	return (0);
}
