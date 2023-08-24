#include "main.h"

/**
 * _stat - checks if a command/executable exist in path
 *
 * @cmd: command to check
 * Return: ptr
 */
char *_stat(char *cmd)
{
	char *paths, *path, *buffer, *tmp;
	struct stat status;
	int i = 0;

	if (*cmd == '.')
		return (cmd);
	if (*cmd == '/')
	{
		if (stat(cmd, &status) != 0)
			return (NULL);
		return (cmd);
	}
	paths = _strdup(getenv("PATH"));
	if (paths)
	{
		path = strtok(paths, ":");
		while (path)
		{
			tmp = _strdup(path);
			buffer = malloc(500);
			while (i < 500)
			{
				buffer[i] = '\0';
				i++;
			}
			sprintf(buffer, "%s/%s", tmp, cmd);
			free(tmp);
			if (stat(buffer, &status) == 0)
				return (buffer);
			free(buffer);
			path = strtok(NULL, ":");
		}
	}
	return (NULL);
}
