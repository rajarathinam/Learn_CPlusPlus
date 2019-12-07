#include "stub.h"
bool isPalindromeWithBeginAndEnd(char *beg, char* end)
{
    bool result = true;
    if(beg != nullptr && end !=nullptr )
    {

         if( (strlen(beg) !=0)  && (strlen(end) != 0))
         {
             while(beg < end)
         {
             if( *beg != *end)
             {
                  result = false;
                  break;
             }
             beg++;
             end--;
         }
         }
    }
    return result;
}

int afewqfef3()
{
    char *in_string = "";
    if(isPalindromeWithBeginAndEnd(in_string+0,in_string+4))
    {
        cout << "Yes";
    }
                else
        {
                cout << "No";
    }
                        cout <<endl;
    return 0;
}
