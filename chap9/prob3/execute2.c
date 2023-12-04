#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main( ) 
{
	printf("Parent process start\n");
	if (fork( ) == 0) 
	{
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr,"First fail"); 	
		exit(1);													}

	if (fork( ) == 0)
	{
		execl("/bin/date", "date", NULL);											fprintf(stderr,"Second fail");
		exit(2);
	}

	if (fork( ) == 0) 
	{
		execl("/bin/ls","ls", "-l", NULL);
		fprintf(stderr,"Third fail");
		exit(3);
	}


	printf("Parent process done\n");
}

