#include <unistd.h>
#include <stdio.h>
int main(){
	printf("i am %d child of %d\n", getpid(), getppid());
}
