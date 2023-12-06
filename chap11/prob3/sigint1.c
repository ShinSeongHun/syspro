#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void intHandler();

int main()
{
	signal(SIGINT, intHandler);
	while(1)
		pause();
	printf("Can't run");
}

void intHandler(int signo)
{
	printf("interrupt signal hand \n");
	printf("signal number : %d\n", signo);
	exit(0);
}
