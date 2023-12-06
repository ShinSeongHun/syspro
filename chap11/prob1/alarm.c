#include <stdio.h>
#include <unistd.h>
unsigned int alarm(unsigned int sec);

int main()
{
	int n = 1;
	alarm(5);
	printf("Loop start \n");
	while(1)
	{
		sleep(1);
		printf("%d seconds \n", n);
		n++;
	}

	printf("Can't run \n");
}
