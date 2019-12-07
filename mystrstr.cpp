#include<iostream>
#include<string.h>
using namespace std;

char *mystrstr(char *str1, char *find)
{
	int l1 = strlen(str1);
	int l2 = strlen(find);
	 while(l1 > l2)
	 {
		 if(memcmp(str1,find,l2) == 0)
			 return  str1;
		 str1++;
		 l2--;
	 }

}
int ccg()
{
    char *ptr = "RajaRathinam";
    cout<<mystrstr(ptr,"Rathi")<<endl;
    return 0;
}
