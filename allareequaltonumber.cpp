#include "stub.h"
#include "book.h"
bool allareequaltonumber(int x, int y,int z , int num)
{
    return( (( x ^ num ) == 0 ) && ((y ^ num) ==0) && ((z ^ num) == 0));
}

int xsdxd()
{


    int a,b,c;
    a=b =c = 200;
    if(allareequaltonumber(a,b,c,400))
    {
        cout << "\n All are same";
    }
    else
    {
        cout << "\n Not Same";
    }


    cout << endl;
    return 0;
}
