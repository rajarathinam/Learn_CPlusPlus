#include "stub.h"

int fib(int num)
{
	if ( num == 0 )
		return 0;
	else if(num == 1)
		return  1;
	else
	{
		return ( fib(num-1) + fib(num - 2));
	}
}


int sjfekp()
{
	int n;
	cout<<"Enter the value of n to find  Fib(n):";
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}
