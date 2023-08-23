#include "main.h"

/**
 * _execve - runs command
 *
 * @command: command to run
 * @sh : shell name
 * @n: line number
 * @env: shell env variables.
 * Return: 0 on success
 */
int _execve(char **command, char *sh, int n, char **env)
{
	pid_t pid;

	if (handle_builtins(command[0], env) == 0)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		if (execve(command[0], command, env))
			dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", sh, n, command[0]);
	}
	else
		wait(NULL);
	return (0);
}
