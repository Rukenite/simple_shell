#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *buff;
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
	
	printf("I read %d Value read is: %s", num_read, buff);	
	free(buff);
	
	return (0);
}
