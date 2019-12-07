#include "stub.h"

void specialReverse(std::string& str)
{

    int endIndex = str.length() - 1;
    int startIndex = 0;
    while ( startIndex < endIndex) {
        if(!std::isalpha(str[startIndex])) {
            ++startIndex;

        } else if (!std::isalpha(str[endIndex])) {
            --endIndex;
        }
        else {
            std::swap(str[startIndex], str[endIndex]);
            ++startIndex;
            --endIndex;
        }
    }
}
;

int main()
{
    std::string str = "Ab,c,de!$";
    specialReverse(str);
    std::cout << str << std::endl;
    return 0;
}
