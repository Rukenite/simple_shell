#include <stdio.h>
#include <unistd.h>
int main()
{
	int x = 4;

	char *dup[] = {"/bin/ls", "-l", NULL};
	pid_t proc = fork();
	if (proc == 0)
	{
		printf("child runs..");
		if (execve(dup[0], dup, NULL))
			perror("cant run from child");
	}
	printf("parenit runs..");
	if (execve(dup[0], dup, NULL))
		perror("cant run from parent");
}
