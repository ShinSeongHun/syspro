#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( ) 
{
	printf("Parent process start\n");
	if (fork( ) == 0) 
	{
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr,"첫 번째 실패"); 
		exit(1);
	}
	printf("Parent process done\n");
}

