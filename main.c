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
	char *line, **command, *builtins[] = { "help", "exec", "exit", "echo", "cd" };
	size_t n = 0, ln = 1;

	while (1)
	{
		n = 0;
		line = malloc(n);
		printf("prompt>_ ");
		getline(&line, &n, stdin);
		if (feof(stdin))
		{
			free(line);
			putchar('\n');
			return (0);
		}
		fflush(stdin);
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
		ln++;
	}
	return (0);
}

