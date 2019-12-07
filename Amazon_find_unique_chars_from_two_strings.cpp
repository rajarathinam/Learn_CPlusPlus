#include "stub.h"
vector<char> findUniqueCharsFromStrings(const string& s1,const string& s2)
{
    std::vector<char> diff;
    std::set_symmetric_difference (s1.begin(), s1.end(), s2.begin(),s2.end(),
                           std::inserter(diff, diff.begin()));
    return diff;

}

int sefrerr()
{
     string str1 = "Vellore";
     string str2 = "RayaNellore";
     std::sort(str1.begin(),str1.end());
     std::sort(str2.begin(),str2.end());
     auto last1 = unique(str1.begin(),str1.end());
     auto last2 = unique(str2.begin(),str2.end());
     str1.erase(last1,str1.end());
     str2.erase(last2,str2.end());

     vector<char> output = findUniqueCharsFromStrings(str1, str2);
     for(char x:output)
     {
         cout << x << ' ';
     }


    cout << '\n';
    return 0;
}
