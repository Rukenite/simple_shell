#include "main.h"

/**
 * _strtok - formats input into 'command options and arguments if any.
 *
 * @lineread: command inputed from shell
 * Return: ptr to formated command on success
 */
char **_strtok(char *lineread)
{
	char *cmd, **command;
	int i = 0;

	cmd = strtok(lineread, " ");
	if (!cmd)
		return (NULL);
	command = malloc(sizeof(char *) * MAXSIZE);
	while (cmd)
	{
		command[i] = strdup(cmd);
		cmd = strtok(NULL, " ");
		i++;
	}
	command[i] = NULL;
	return (command);
}
