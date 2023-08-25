#include "main.h"

/**
 * _env - prints shell environment variables
 *
 * @environ: arrays of variables
 */
void _env(char **environ)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);
}
/**
 * handle_builtins - Handle passed builtins
 *
 * @builtin: str to compare
 * @environ: environmental variables
 * Return: 0 on Success.
 */
int handle_builtins(char **builtin, char **environ)
{
	int status = 0;

	if (strcmp(builtin[0], "exit") == 0)
	{
		if (builtin[1])
			status = atoi(builtin[1]);
		_free(builtin);
		if (status < 0)
			return (status);
		_exit(status);
	}
	else if (strcmp(builtin[0], "env") == 0)
	{
		_env(environ);
		return (0);
	}
	return (1);
}
