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
	
	if (*lineread == '#')
		return (NULL);
	cmd = strtok(lineread, " ");
	if (!cmd)
		return (NULL);
	command = malloc(sizeof(char *) * MAXSIZE);
	while (command[i])
	{
		command[i] = NULL;
		i++;
	}
	i = 0;
	while (cmd)
	{
		if (*cmd == '#')
			break;
		command[i] = strdup(cmd);
		cmd = strtok(NULL, " ");
		i++;
	}
	return (command);
}
