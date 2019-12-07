#include "stub.h"


void Binary(int n)
{
	static int A[2];
	if(n<1)
	{
		printf("%d\n",A);
	}
	else
	{
		A[n-1] = 0;
		Binary(n-1);
		A[n-1]=1;
		Binary(n-1);
	}
}
int dsmzslk()
{
	Binary(2);
	return 0;
}