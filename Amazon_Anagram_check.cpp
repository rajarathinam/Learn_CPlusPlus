#include "stub.h"

int *fun()
{
   int arr[100];

   /* Some operations on arr[] */
   arr[0] = 10;
   arr[1] = 20;

   return arr;
}

int ehwhwqjlqml()
{
    int *ptr = fun();
    cout << ptr[0] << " " << ptr[1];
    //return 0;
}
