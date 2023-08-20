#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#define SIZE 1000

/**
 * _execve - runs a command/program
 *
 * Return: 0 on success
 */
int main(){
	unsigned int n = 0, i = 0;
	char *buf, *ptr, *cmd[SIZE];
	int status;
	pid_t proc;

	while (1)
	{
		printf("$ ");
		buf = malloc(0);
		if (!buf)
			return (0);
		if (!getline(&buf, &n, stdin))
		{
			perror("Can't read from stdin");
	                exit(EXIT_FAILURE);
		}
		ptr = strtok(buf, "\n");
		ptr = strtok(buf, " ");
		cmd[i] = strdup(buf);

		if (strlen(cmd[i]) == 1)
		{
			free(buf);
			continue;
		}
		while (ptr)
		{
			ptr = strtok(NULL, " ");
			if (ptr)
				cmd[i] = strdup(ptr);
			i++;
		}
		cmd[i] = NULL;
		proc = fork();
		if (proc == 0)
		{
			if (execve(cmd[0], cmd, NULL) == -1)
				perror("error");
		}
		else
			wait(&status);
	}
	return (0);
}
