#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *path = getenv("PATH");

	while (*path)
	{
		if (*path == ':')
		{
			putchar('\n');
			path++;
			continue;
		}
		putchar(*path);
		path++;
	}
	putchar('\n');
}
