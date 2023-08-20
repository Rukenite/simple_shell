#include <stdio.h>

extern char **environ;
int main(int ac, char **av, char **env)
{
	printf("address env - %p, address environ - %p\n", env, environ);
	if (env == environ)
		printf("They are the same\n");
	else 
		printf("They are not the same\n");
}
