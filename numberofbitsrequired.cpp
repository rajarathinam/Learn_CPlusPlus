
#include "stub.h"

int numberOfBitsAtoB(int x, int y)
{
    if( x == y)
        return 0;

    int count  = 0;
    int c = x ^ y;
    while(c != 0)
    {
            count += c & 1;
            c = c >> 1;
        }
        return count;
}


int aaa()
{

    cout << "\nNumber Of bits Required:" << numberOfBitsAtoB(5,8);



    cout << endl;
    return 0;
}
