#include "stub.h"

 void selectionsort(int a[], int n)
 {
	/* advance the position through the entire array */
/*   (could do j < n-1 because single element is also min element) */
	 int i,j,iMin;
for (j = 0; j < n-1; j++) {
    /* find the min element in the unsorted a[j .. n-1] */
 
    /* assume the min is the first element */
    iMin = j;
    /* test against elements after j to find the smallest */
    for ( i = j+1; i < n; i++) {
        /* if this element is less, then it is the new minimum */  
        if (a[i] > a[iMin]) {
            /* found new minimum; remember its index */
            iMin = i;
        }
    }
 
    swap(a[j], a[iMin]);
		if( 1 == j)
		{
			cout<<"Second Smallest:"<<a[j]<<"\n";
			break;
		}
	 }
 }
 int sd()
 {

	 int a[] = {3,43,12,5,1};
	 selectionsort(a,5);
	 return 0;
 }
