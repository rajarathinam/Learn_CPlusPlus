
#include<iostream>
using namespace std;
/*
void insertionSort(int arr[], int n)
{
int i, j,k;
	for(j=1;j<n;j++)
	{
	k=arr[j];
	for(i=j-1;i>=0 && k<arr[i];i--)
	arr[i+1]=arr[i];
	arr[i+1]=k;
	//printf ("\nPass %d, Element inserted in proper place: %d\n",j,k);



      }
}

      int hengrkp()
      {
    	  int array[]={5,4,1,3,2};

    	  insertionSort(array,5);
		  return 0;
      }

*/
int vdv()
{
	int A[]= {1,2,3};
	int i,valueToInsert,holePos,n=3;
for (i = 1; i < n; i++)
  {
    // at the start of the iteration, A[0..i-1] are in sorted order
    // this iteration will insert A[i] into that sorted order
    // save A[i], the value that will be inserted into the array on this iteration
    valueToInsert = A[i];
    // now mark position i as the hole; A[i]=A[holePos] is now empty
    holePos = i;
    // keep moving the hole down until the valueToInsert is larger than 
    // what's just below the hole or the hole has reached the beginning of the array
    while (holePos > 0 && valueToInsert < A[holePos - 1])
      { //value to insert doesn't belong where the hole currently is, so shift 
        A[holePos] = A[holePos - 1] ;//shift the larger value up
        holePos = holePos - 1  ;     //move the hole position down
      }
    // hole is in the right position, so put valueToInsert into the hole
    A[holePos] = valueToInsert;
    // A[0..i] are now in sorted order
  }
return 0;
}
