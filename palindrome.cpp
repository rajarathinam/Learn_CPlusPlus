#include "stub.h"


bool isPalindrome(char *str)
{
    if(NULL == str)
        return false;
    char *begin = str;
    char *end = str;
    while(*end)
    {
       end++;
    }
    end--;

    while( begin < end)
    {
        if( *begin != *end)
        {
            return false;
        }
        begin++;
        end--;
    }
    return true;

}
int wssmain()
{
    char *name = "ANqaNA";
    if(isPalindrome(name))
        cout << "\nPalindrome";
    else
        cout << "\nNot a Palindrome";
    return 0;

}
