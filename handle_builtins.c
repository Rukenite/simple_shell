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
int handle_builtins(char *builtin, char **environ)
{
	if (strcmp(builtin, "exit") == 0)
		_exit(0);
	else if (strcmp(builtin, "env") == 0)
	{
		_env(environ);
		return (0);
	}
	return (1);
}
