#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
unsigned int alarm(unsigned int sec);

void alarmHandler();

int main()
{
	int n = 1;
	signal(SIGALRM, alarmHandler);
	alarm(5);
	printf("Loop Start \n");
	while(1)
	{
		sleep(1);
		printf("%d second \n", n);
		n++;
	}
	printf("Can't run");
}

void alarmHandler(int signo)
{
	printf("Wake up\n");
	exit(0);
}
