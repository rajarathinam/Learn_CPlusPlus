#include "stub.h"
#include <string.h>

char *mystrcat(char *dst,const char *src)
{
	if(strlen(dst)< strlen(src))
	{
		cout<<"Destination has less space"<<endl;
		return 0;
	}
	char *temp=dst;
	while(*src)
		*dst++ = *src++;
	    *dst = '\0';
	return temp;
}
int bakmw()
{
	char *str1 = "RajaR";
	char str2[25];
    cout<<mystrcat(str2,str1)<<endl;
	return 0;
}



