#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int p1, p2;
	p1 = fork();
	if (p1 == 0)
	{
		printf("Hello\n");
	}
	p2 = fork();
	if (p2 == 0)
	{
		printf("Hello\n");
		exit(0);
	}
	return 0;
}
