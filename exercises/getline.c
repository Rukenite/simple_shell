#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *buff, *str;
	size_t n = 32;
	int num_read;

	printf("$ ");
	/* Allocating buffer to store string*/
	buff = malloc(sizeof(char) * n);
	if (!buff)
	{
		perror("Malloc failed!");
		return (1);	
	}

	num_read = getline(&buff, &n, stdin);
	if (num_read == -1)
	{
		perror("Read failed");
		return (1);
	}
	
	/* Implementing strtok */
	str = strtok(buff, " ");
	while (str)
	{
		printf("%s\n", str);
		str = strtok(NULL, "\n"); // change made was replacing str with NULL
	}
	/* Next to implement are execve, fork, wait, sleep, stat*/

	free(buff);
	
	return (0);
}
