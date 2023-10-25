#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	int check;
	char c;
	struct book bk;
	if (argc < 2) 
	{
		fprintf(stderr, "How to use : %s FileName\n", argv[0]);
		exit(1);
	}
	if ((fd = fopen(argv[1], "bk")) == NULL)
	{
		fprintf(stderr, "Error Open File\n");
		exit(2);
	}

	printf("0 : list of all books, 1 : list of available books ) ");
	scanf("%d", &check);
	if (check == 0)
	{
		printf("%-2s %-8s %-6s %-4s %-11s %6s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
		while (fread(&bk,sizeof(bk), 1, fd) > 0)
		{
			if(bk.id != 0)
			printf("%-2d %-8s %-6s %-4d %-11d %6s", bk.id, bk.bookName, bk.writer, bk.year, bk.count, bk.sts == 0 ? "True" : "False");
		}
	}

	if (check == 1)
	{
		fseek(fd, (id-START_ID)*sizeof(bk), SEEK_SET);
		if((fread(fd, (char *) & bk, sizeof(bk)) > 0) && (bk.sts != 0))
		{
			printf("%-2s %-8s %-6s %-4s %-11s %6s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
			printf("%-2d %-8s %-6s %-4d %-11d %6s", bk.id, bk.bookName, bk.writer, bk.year, bk.count, "True");
		}
		else printf("There are no books You can borrow\n");
	}



	fclose(fd);
	exit(0);
}



