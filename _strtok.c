#include "main.h"

/**
 * _strtok - formats input into 'command options and arguments if any.
 *
 * @lineread: command inputed from shell
 * Return: ptr to formated command on success
 */
char **_strtok(char *lineread)
{
	char *cmd, **command, *copy;
	int i = 0, each_word = 1, index = 0;

	strtok(lineread, "\n");
	copy = strdup(lineread);
	cmd = strtok(lineread, " ");
	if (!cmd)
	{
		free(lineread);
		return (NULL);
	}
	while (cmd)
	{
		each_word++;
		cmd = strtok(NULL, " ");
	}
	free(lineread);
	command = malloc((sizeof(char *) * each_word) + 1);
	while (i < (each_word + 1))
	{
		command[i] = NULL;
		i++;
	}
	cmd = strtok(copy, " ");
	while (cmd)
	{
		command[index] = strdup(cmd);
		cmd = strtok(NULL, " ");
		index++;
	}
	free(copy);
	return (command);
}
