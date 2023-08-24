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

	copy = _strdup(lineread);
	cmd = strtok(copy, " ");
	if (!cmd)
	{
		free(lineread);
		free(copy);
		return (NULL);
	}
	while (cmd)
	{
		each_word++;
		cmd = strtok(NULL, " ");
	}
	free(copy);
	command = malloc(sizeof(char *) * each_word);
	while (i < (each_word))
	{
		command[i] = NULL;
		i++;
	}
	cmd = strtok(lineread, " ");
	while (cmd)
	{
		command[index] = _strdup(cmd);
		cmd = strtok(NULL, " ");
		index++;
	}
	/*free(lineread);*/
	return (command);
}
