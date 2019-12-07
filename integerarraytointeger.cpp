#include "stub.h"

int arraytointeger(int arr[] , int n)
{  
	int arraysize = n;
//	cout << arr + 1 - (arr);
	cout << "\nSize Of Array:" << arraysize;
	int result = 0;
	if(arraysize == 1)
		return arr[0];
	else
	{
		
		for(int i= 0; i < arraysize ; i++)
		{
          result*=10;
		  result+=arr[i];
		}
	}
	return result;
}

int mawwwin()
{
	int a[2][3] = { 
						{1,2,3},
						{4,5,6}
					};
	cout << **a << "\n";
	cout << *(a+0) << "\n";
	cout << *(a+1) << "\n";

	cout << *a[1] << "\n";

	//cout << "\nInteger Value :" <<arraytointeger(array,4);
	cout <<"\n";
	return 0;
}