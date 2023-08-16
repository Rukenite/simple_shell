#include <unistd.h>
#include <stdio.h>

/**
 * main - program that prints the PID of the parent process
 */
void main(void)
{
	printf("I am %d child of %d\n", getpid(), getppid());
}
