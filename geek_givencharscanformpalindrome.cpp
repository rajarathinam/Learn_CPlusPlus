#include "stub.h"
bool  isOddNumber(pair<char,int> x)
{
    return (x.second & 0x01);
}


bool canFormPalindrome(string str)
{
    bool result = false;
    map<char,int> mymap;
    int str_length = str.length();
    for(int i = 0; i < str_length ; ++i)
    {
       mymap[str.at(i)]++;
    }
    int  oddCount = count_if(mymap.begin(),mymap.end(),isOddNumber);
    int evenCount = str_length - oddCount;
    if( (oddCount & 0x01) && !(evenCount & 0x01))
        result = true;
    else if(oddCount && !(evenCount & 0x01))
        result = true;

    return result;

}

int wasgf4r()
{
    string input = "abab";
    if(canFormPalindrome(input))
        cout << "Yes..OK";
    else
        {
                cout << "NOoooooooooooooooooooooooo";
}

    return 0;
}
