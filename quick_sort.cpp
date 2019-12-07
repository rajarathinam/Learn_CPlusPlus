#include <iostream>
#include <iomanip>

using namespace std;

#define SIZE 5

/* swap a[i] and a[j] */
void swap(int a[], int i, int j)
{	
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void print(const int arr[])
{
	for(int i=0;i < SIZE; i++) {
		cout << setw(3) << arr[i];
	}
	cout << endl;
}
/*

void qsort(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = a[(left_index + right_index) /2];

        // partition
	while(left <= right) 
	{
		while(a[left] < pivot) 
			left++;
		while(a[right] > pivot)
			right--;
		if(left <= right)
		{
			swap(a,left,right);
			left++;
			right--;
		}
		print(a);		
	}
    
        // recursion
	qsort(a,left_index,right);
	qsort(a,left,right_index);
}
*/

int partition(int *a, int low, int high)
{
	int pivot_item = a[low];
	int left = low;
	int right = high;
	int pivot = low;
	while(left < right)
	{
		 while( a[left] <= pivot_item)
			 left++;
		 while( a[right] > pivot_item)
			 right--;
		 if( left < right)
		 {
			 swap(a,left,right);
		 }
	}
	  /* right is final position for the pivot */
  a[low] = a[right];
  a[right] = pivot_item;
  return right;
}
void qsort( int *a, int low, int high)
{
	if( high > low)
	{
		int pivot = partition(a,low,high);
		qsort(a,low,pivot-1);
		qsort(a,pivot + 1,high );
	}
}
int qwa()
{
	int a[]={2,4,1,5,3};
	print(a);
	qsort(a,0,SIZE-1);
	return 0;
}