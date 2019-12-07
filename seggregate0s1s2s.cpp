#include "stub.h"

void sort012_alt(int arr[], int size)
{
	int mid =0;
	int high = size - 1;
	int low = 0;

	while( mid <= high)
	{
		switch(arr[mid])
		{
		case 0:
			swap(arr[low++],arr[mid++]);
			break;
			/*
		case 2:
            mid++;
			break;
			*/
			
		case 1:
			swap(arr[mid],arr[high--]);
			break;
			

		}
	}
}

int aahbjw()
{
	int array[] = { 0,0,1,1,1,0,0,1,0};
    sort012_alt(array,12);
	for(int i = 0; i < 9;i++)
	{
		cout << array[i] << " " <<"\n";
	}
	return 0;
}
