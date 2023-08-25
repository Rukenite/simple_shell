#include "main.h"

/**
 * main - a simple command line interpreter
 *
 * @ac: number of args passed
 * @av: argus passed
 * @env: env variables
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char *av[], char **env)
{
	char *line, *eachline, *cmd, **command;
	size_t n, ln = 0;

	while (1)
	{
		n = 1;
		if (isatty(STDIN_FILENO))
			printf("prompt>_ ");
		line = malloc(n);
		getline(&line, &n, stdin);
		if (feof(stdin))
		{
			free(line);
			if (isatty(STDIN_FILENO))
				putchar('\n');
			_exit(0);
		}
		fflush(stdin);
		ln++;
		if (*line == '\n')
		{
			free(line);
			continue;
		}
		eachline = strtok(line, "\n");
		while (eachline != NULL)
		{
			cmd = _strdup(eachline);
			command = _strtok(cmd);
			eachline = strtok(NULL, "\n");
			free(cmd);
		}
		free(line);
		if (!command)
			continue;
		if (_execve(command, av[0], ln, env) == 1)
			continue;
		_free(command);
	}
	return (0);
}

