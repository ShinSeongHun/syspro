nclude <stdio.h>
#include <string.h>
#define MAXLINE 100
#define MAXLINES 5

char lines[MAXLINES][MAXLINE];
char longest[MAXLINE];
void copy(char from[], char to[]);


int main()
{
	   int i = 0, len, max = 0;

	      while(i < MAXLINES && fgets(lines[i], MAXLINE, stdin) != NULL) {
		            len = strlen(lines[i]);
			          if (len > max) {
					           max = len;
						            copy(lines[i], longest);
							          }
				        i++;
					   }
	         

	          for(int a = 0; a < MAXLINES; a++)
			      {
				              char tmp = 0;
					              if(*lines[a] > *lines[a + 1])
							              {
									                  tmp = *lines[a];
											              *lines[a] = *lines[a + 1];
												                  *lines[a + 1] = tmp;
														          }
						          }
		      
		      for (int j = 0; j < MAXLINES; j++) {
			            printf("%s", lines[j]);
				       }
		         return 0;
}

void copy(char from[], char to[])
{
	   int i = 0;
	      while ((to[i] = from[i]) != '\0')
		            ++i;
}
