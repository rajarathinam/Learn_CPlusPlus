#include "stub.h"

#define MAX 32

vector<int> decimal2binary(int num)
{
    vector<int> v;
    for(int i = MAX - 1; i >=0 ; i--)
    {
        v.push_back((num >> i) & 1);
    }
    return v;
}
string decimal2nagativebinary(int num)
{
    if( num < 0)
    {

        bitset<MAX> negative(num);
        return (negative.to_string());
    }

}

int binary2decimal(vector<int> bin)
{

    int decimal = 0;
    if(bin.empty())
        return 0;
    for(auto it : bin)
    {
        decimal  = decimal << 1 | it;
    }

    return decimal;




}

int jakaj()
{


    int x = -3 ;
    string out = decimal2nagativebinary(x);
    cout<<"\nBinary Value:" << out ;

    //cout << "\nDecimal Value:" << binary2decimal(out);



    cout << endl;
    return 0;
}
