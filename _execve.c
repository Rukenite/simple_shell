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
	int stat, stats;

	stat = handle_builtins(command, env);
	if (stat == 0)
	{
		_free(command);
		return (-1);
	}
	else if (stat < 0)
	{
		dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %d\n", sh, n, stat);
		return (-1);
	}
	com = _stat(command[0]);
	if (!com)
	{
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", sh, n, command[0]);
		_free(command);
		return (-1);
	}
	command[0] = com;
	pid = fork();
	if (pid == 0)
	{
		execve(command[0], command, env);
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", sh, n, command[0]);
	}
	else
		wait(&stats);
	if (feof(stdin))
		return (WEXITSTATUS(stats));
	return (0);
}
