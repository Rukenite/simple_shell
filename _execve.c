#include "main.h"

/**
 * _execve - runs command
 *
 * @command: command to run
 * @sh : shell name
 * @n: line number
 * Return: 0 on success
 */
int _execve(char **command, char *sh, int n)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command[0], command, NULL))
		{
			dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", sh, n, command[0]);
			_free(command);
		}
	}
	else
		wait(NULL);
	return (0);
}
