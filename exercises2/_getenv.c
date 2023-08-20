#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;
char *_getenv(const char *name)
{
	char *dup;
	int len = strlen(name), i = 0;

	while (environ[i])
	{
		dup = strdup(environ[i++]);
		if (strncmp(name, dup, len) == 0)
			return (dup);
	}
	return (NULL);
}
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("format: %s var to search\n", av[0]);
		exit(1);
	}
	printf("%s\n", _getenv(av[1]));
	return (0);
}
