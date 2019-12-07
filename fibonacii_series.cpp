#include "stub.h"

int cxbkck()
{

int a=0,b=1,c=0,n;
cout<<"Enter the number of terms you wanna see: ";
cin>>n;
if(n == 1)
	cout <<a<< "";
else if( 2 == n)
	cout<<a<<" "<<b<<" ";
else
{
	cout<<a<<" "<<b<<" ";
for(int i=1;i<=n-2;i++)
{
c=a+b;
a=b;
b=c;
//Coding by: Snehil Khanor
//http://WapCPP.blogspot.com
cout<<c<<" ";
}
}
return 0;
}
