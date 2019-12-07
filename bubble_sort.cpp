#include "stub.h"

void bubble_sort(int a[], int length)
{
	int n = length ;
	for(int i = 0; i < n-1 ; i++)
	{
		for(int j = 1; j < (n - i) ; j++)
		{
			if(  a[ j-1] > a[j])
				swap(a[j-1],a[j]);
		}
	}
}
int wjoww()
{

	
	int array[] = {5,1,4,2,8};
	
	bubble_sort(array,5);
	return 0;
}