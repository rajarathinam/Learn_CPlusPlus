#include<stdio.h>
#include<stdlib.h>
 
int lis( int arr[], int n )
{
   int *lisindex=(int *)malloc(sizeof(int) * n);
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
   int lastLISindex;
   int check,k=0;
   
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   for ( i = 1; i < n; i++ )    {
      for ( j = 0; j < i; j++ ) {
         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)   {
            lis[i] = lis[j] + 1;
            lisindex[i]=j;
      }
   }
   }
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )    {
      if ( max < lis[i] )
         max = lis[i];
         lastLISindex=i;
   }
   
   int *arrSeq=(int *)malloc(sizeof(int) * max);
   
   for(int index=max-1;index>=0;index--) {
       arrSeq[index]=arr[lastLISindex];
       lastLISindex=lisindex[lastLISindex];
   }
   
   for(int index=0;index<max;index++)   {
       printf("%d ",arrSeq[index]);
   }
   
   /* Free memory to avoid memory leak */
   free( lis );
 
   return max;
}
 
/* Driver program to test above function */
int asjksjwn2eldmk()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  lis( arr, n ); 
 
  getchar();
  return 0;
}