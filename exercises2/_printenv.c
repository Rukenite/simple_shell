#include <stdio.h>

extern char **environ;
int main(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
}
