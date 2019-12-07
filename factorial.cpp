
#include "stub.h"
int fact(int num)
     {
     if( num == 0 || num == 1)
         return 1;
     else
       return num * fact(num -1);
 }

int aswdw()
{

    int N =18;
      // cin >> N;
       if( N & 0x01)
           cout << "Weird";
       else
       {
         if( (2 <= N) && (N <= 5))
         {
             cout << "Not Weird";
         }
         else if((6 <= N) && (N<=20))
         {
             cout << "Weird";
         }
         else if( N > 20)
         {
               cout << "Not Weird";

         }
       }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 3;

    cout << fact(n);
    return 0;
}
