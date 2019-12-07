#include<iostream>
using namespace std;

#include <iostream>
#include <cmath>
#include <set>
#include<algorithm>
#include <string>
#include "test.h"
using namespace std;
bool isomorphic(char *str1, char *str2)
{
	int hashmap[256] = {0};
	bool result =true;
	
	while( *str1 != '\0')
	{
		if(hashmap[*str1] == 0)
		{
			hashmap[*str1] = int(*str2);
		}
		else if ( hashmap[*str1] == int(*str2))
		{
		}
		else if ( hashmap[*str1] != int( *str2))
		{
			result = false;              
			break;
		}
		str1++;
	}
	return result;
   
}

int qwdw()
{
int flag=0;
string a="app";
string b="fos";
//cout<<a<<b;
if(a.length()!=b.length())
{
cout<<"sorry ASS"<<endl;
flag=1;
}
int hashmap[256]={0};
for(int i=0;i<a.length();i++)
{
if(hashmap[a[i]]==0)
{
hashmap[a[i]]=int(b[i]);
//cout<<a[i]<<hashmap[a[i]]<<endl;;
}else if((hashmap[a[i]])==int(b[i]))
{
//cout<<"good to go"<<endl;;
}else
if ((hashmap[a[i]])!=b[i])
{
//cout<<"sorry Ass"<<endl;
flag=1;
break;
}
}
if(!flag)
cout<<"true";
else
cout<<"false";
}
