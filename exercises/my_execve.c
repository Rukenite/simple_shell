#include <stdio.h>
#include <unistd.h>

/*
 *  execve - This functions allows a process execute another program,
 *  it allow the new program to be loaded into the current process,
 *  and does not return to the previous process.
 */

/*
 *char **environ - this is a pointer to the current environment
 */

extern char **environ;

int main(void)
{	
	char *argv[] = {"/bin/ls" "-la", NULL};
	
	printf("Before the execv function");
	
	if(execv(argv[0], argv, environ) == -1)
		perror("Error!");

	printf("Nothing should be printed After execv function if it works\n");

	return (0);
}
