include <stdio.h>
 

void appendFiles(char source[], char destination[])
{
	// declaring file pointers
	FILE *fp1, *fp2;
	// opening files
	fp1 = fopen(source, "a+");
	fp2 = fopen(destination, "a+");
	// If file is not found then return.
	if (!fp1 && !fp2) {
		printf("Unable to open/" "detect file(s)\n");
		return;
	}
	char buf[100];
	fprintf(fp2, "\n");
	while (!feof(fp1)) {
		fgets(buf, sizeof(buf), fp1);
		fprintf(fp2, "%s", buf);
	}
	rewind(fp2);
	while (!feof(fp2)) {
		fgets(buf, sizeof(buf), fp2);
	   	printf("%s", buf);
		}
	}
	                                                                                                                                    
int main()
{
	char source[] = "file1.txt",
	destination[] = "file2.txt";

	appendFiles(source, destination);
	return 0;
}
