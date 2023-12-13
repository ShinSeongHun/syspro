#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void alarmHandler();

int main()
{
	int pid, child, status;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGALRM, alarmHandler);
		alarm(5);
		while(1)
		{
			sleep(1);
			printf("Process [1] Execution\n");
		}

	}
	child = wait(&status);
	printf("child killed\n");
	printf("parent Killed\n");
}

void alarmHandler(int signo)
{
	printf("^cInterrupt to child\n");
	exit(0);
}
