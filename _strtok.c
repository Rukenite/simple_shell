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
	int i = 0, each_word;

	strtok(linread, "\n");
	cmd = strtok(lineread, " ");
	while (cmd)
	{
		each_word++;
		cmd = strtok(NULL, " ");
	}
	command = malloc(sizeof(char *) * each_word);
	cmd = strtok(lineread, "\0");
	while (cmd)
	{
		command[i] = strdup(cmd);
		cmd = strdup(NULL, "\0");
	}

	return (cmd);
}
