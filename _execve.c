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
	char *com;

	if (handle_builtins(command[0], env) == 0)
		return (0);
	com = _stat(command[0]);
	if (!com)
	{
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", sh, n, command[0]);
		free(com);
		return (1);
	}
	command[0] = com;
	pid = fork();
	if (pid == 0)
	{
		execve(command[0], command, env);
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", sh, n, command[0]);
	}
	else
		wait(NULL);
	return (0);
}
