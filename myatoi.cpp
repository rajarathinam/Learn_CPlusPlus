#include<stdio.h>
//#include "test.h"
extern int x;

int myatoi( char* pStr ) 
{
  int iRetVal = 0; 
 
  if ( pStr )
  {
    while ( *pStr && *pStr <= '9' && *pStr >= '0' ) 
    {
      iRetVal = (iRetVal * 10) + (*pStr - '0');
      pStr++;
    }
  } 
  return iRetVal; 
}
int ctchv(int argc, char* argv[])
{
printf("\n%d\n", myatoi("423"));

return(0);
}

/*

int myatoi(const char *string)
{
int i;
i=0;
while(*string)
{
i=(i<<3) + (i<<1) + (*string - '0');
string++;
// Dont increment i!
}
return(i);

}
*/