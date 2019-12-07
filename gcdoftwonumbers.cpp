
#include "stub.h"

int gcd(int a, int b)
{
    if( 0 == b)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}


int qww()
{



   cout << "GCD:" << gcd(20,120);

    cout << endl;
    return 0;
}
