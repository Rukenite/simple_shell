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
	int i = 0, each_word = 1, sig = 0;

	strtok(lineread, "\n");
	copy = strdup(lineread);
	strtok(lineread, " ");
	while (strtok(NULL, " "))
		each_word++;
	sig = 1;
	if (!sig)
	{
		free(lineread);
		return (NULL);
	}
	free(lineread);
	command = malloc((sizeof(char *) * each_word) + 1);
	while (command[i])
	{
		command[i] = NULL;
		i++;
	}
	cmd = strtok(copy, " ");
	while (cmd)
	{
		command[i] = strdup(cmd);
		cmd = strtok(NULL, " ");
		i++;
	}
	free(copy);
	return (command);
}
