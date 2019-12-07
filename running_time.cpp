#include <time.h>
#include <stdio.h>

void xstrrev(char *s)
{
	char *t=s;
	while(*t !='\0')
		t++;
	while(s<t)
	{
		int c=*s;
		*s++=*--t;
		*t=c;
	}
}
int huh()
{
  clock_t start, end;
  double runTime;
  start = clock();
  char str[]="Raja";
  xstrrev(str);
  printf("%s\n",str);
  /* my actual program */
  end = clock();
  runTime = (end - start) / (double) CLOCKS_PER_SEC ;
  printf ("Run time is %f seconds\n", runTime);
  getchar();
  return 0;
}
