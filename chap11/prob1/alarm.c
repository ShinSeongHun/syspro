#include <stdio.h>
#include <unistd.h>
unsigned int alarm(unsigned int sec);

int main()
{
	alarm(5);
	printf("Loop start \n");
	while(1)
	{
		sleep(1);
		printf("1 seconds \n");
	}

	printf("Can't run \n");
}
