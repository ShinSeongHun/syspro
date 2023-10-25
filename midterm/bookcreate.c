#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main(int argc, char *argv[])
{
	struct book bk;
	FILE *fp;
	
	if (argc != 2)
	{
		fprintf(stderr, "How to use : %s Filename\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "wb");
	printf("%-2s %-8s %-6s %-4s %-11s %-6s", "id", "bookname", "author", "year", "numofborrow", "borrow");
	while (scanf("%d %s %s %d %d %d", &bk.id, &bk.bookName, &bk.writer, &bk.year, &bk.count, &bk.sts) == 6)
	{
		fwrite(&bk, sizeof(bk), 1, fp);
	}
	
	fclose(fp);
	exit(0);
}
