#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

/**
 * _execve - runs a command/program
 *
 * Return: 0 on success
 */
int main(){
	unsigned int n = 0, i = 0;
	char *buf, *ptr, *cmd[SIZE];

	buf = malloc(0);
	if (!buf)
		return (0);
	printf("$ Enter command/program to run.. ");
	if (!getline(&buf, &n, stdin))
	{
		perror("Can't read from stdin");
                exit(EXIT_FAILURE);
	} /* reading from stdin and handling error if read fails */

	ptr = strtok(buf, "\n"); /* reading full line minus newline*/
	ptr = strtok(buf, " "); /*reading command itself */
	printf("running %s...", ptr);
	cmd[i] = strdup(ptr); /* duplicating command into program arg */
	i++;

	while (ptr)
	{
		ptr = strtok(NULL, " ");
		if (ptr)
		{
		cmd[i] = strdup(ptr);
		}
		i++;
	}/* duplicating options/argument into cmd*/
	cmd[i] = NULL; /*indicating end of program*/

	/* running program and also handle error on return */
	if (execve(cmd[0], cmd, NULL))
		exit(EXIT_FAILURE);

	return (0);
}
