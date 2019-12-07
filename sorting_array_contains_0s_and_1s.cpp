#include "stub.h"
void swapx(int &x, int &y)
{
	x=x+y;
	y=x-y;
	x=x-y;
}

void sort(int * a,int len)
{
int i= 0, j = len;
while(j>i)
{
 if(a[i] == 0)
 {
 i++;
 continue;
 }
while(a[--j] == 1);
if(j>i)
swapx(a[i],a[j]);
}
}

int svuode (int argc, char * argv[])
{

return 0;
}
