#include "main.h"

/**
 * test_eof - tests for end of input
 *
 * @line: line to check
 * @stcode: status code
 */
void test_eof(char *line, int stcode)
{
	if (feof(stdin))
	{
		free(line);
		if (isatty(STDIN_FILENO))
			putchar('\n');
		exit(stcode);
	}
	else if (!feof(stdin) && stcode == 2)
	{
		free(line);
		exit(stcode);
	}
}
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
	int *stcode, code = 0;

	stcode = &code;
	while (1)
	{
		n = 1;
		if (isatty(STDIN_FILENO))
			printf("prompt>_ ");
		line = malloc(n);
		getline(&line, &n, stdin);
		test_eof(line, *stcode);
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
			cmd = strdup(eachline);
			command = _strtok(cmd);
			eachline = strtok(NULL, "\n");
			free(cmd);
		}
		free(line);
		if (!command)
			continue;
		if (_execve(command, av[0], ln, env, stcode) == -1)
			continue;
		_free(command);
	}
	return (0);
}
