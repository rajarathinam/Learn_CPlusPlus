#include "stub.h"

int findFirstNonRepeatableCharacter(char *str)
{

    std::pair<int, int> pairs[256];
    for(auto i  = 0 ; i < std::strlen(str); ++i)
    {
        pairs[str[i]].second++;
    }

    int result = 0;
    for(auto i  = 0 ; i < std::strlen(str); ++i)
    {
         if( pairs[str[i]].second ==  1)
         {
         result = i;
         break;
         }
    }

    return result;


}

int strtointeger(const std::string& str)
{
    int result = 0;
    int length = str.length();
    int i = 0;
    while (i < length)
    {
       result = result * 10;
       result = result + ( str[i] - '0');
       ++i;
    }

}

int fact(int n, int result)
{
    if( n == 0) {
        return result;
    } else {
        return fact(n-1, n * result);
    }
}
int vhb()
{
    int result = 1;
    int out = fact(4,1);
    char *str = "total";
    int res = findFirstNonRepeatableCharacter(str);

    char *str1 = "123";
    strtointeger(str1);
    std::cout << str[res] << std::endl;
    return 0;
}
