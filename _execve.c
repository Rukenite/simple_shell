#include "main.h"

/**
 * _execve - runs command
 *
 * @command: command to run
 * Return: 1 on error
 */
int _execve(char **command)
{
	pid_t pid;
	int i = 0;
	char **cmd[MAXSIZE];

	while (i < MAXSIZE)
		cmd[i] = NULL;
	while (command[i])
		cmd[i] = command[i++];
	pid = fork();
	if (pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		return (-1);
	}
	else
		wait(NULL);
	return (0);
}
