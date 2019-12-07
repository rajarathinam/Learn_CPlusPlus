#include "stub.h"

void findLongestUniqueSubstring(const std::string& str)
{
    std::unordered_map<char, int> hashtable;
    int start = 0;
    int end = 0;
    std::string output = "";
    int strSize = static_cast<int>(str.size());
    for (; end < strSize; ++end) {
        char ch = str[end];
        if ( (hashtable.find(ch) != hashtable.end()) ) {
            start = std::max(hashtable[ch] + 1, start);
        }

        if(output.length() < end - start + 1) {
            output = str.substr(start, end + 1);
        }
        hashtable[ch] = end;
    }
    std::cout << output << std::endl;
}

std::vector<string> processStrings(string str1, string str2)
{
    bool arr[256] = { false };
    std::vector<string> output;
    int str1Length = str1.length();
    int str2Length = str2.length();
    for(auto i = 0; i < str2Length; ++i) {
        arr[str2[i]] = true;
    }
    std::string output1 = "";
    for(auto i = 0; i < str1Length; ++i) {
        if( arr[str1[i]] == false) {
            output1.push_back(str1[i]);
        }
    }
    bool arr1[256] = { false };

    for(auto i = 0; i < str1Length; ++i) {
        arr1[str1[i]] = true;
    }
    std::string output2 = "";
    for(auto i = 0; i < str2Length; ++i) {
        if( arr1[str2[i]] == false) {
            output2.push_back(str2[i]);
        }
    }
    output.push_back(output1);
    output.push_back(output2);
    return output;


}
vector<string> compareFriends(vector<string> frndsList)
{
    std::sort(frndsList.begin(), frndsList.end());
    for (auto it = frndsList.begin(); it != frndsList.end();) {
        std::string temp = *it;
        std::reverse(temp.begin(), temp.end());
        std::size_t   comma_index = temp.find(",");
        std::reverse(temp.begin(), temp.begin() + comma_index);
        std::reverse(temp.begin() + comma_index + 1, temp.end());

        auto it1 = std::find(frndsList.begin(), frndsList.end(), temp);
        if( it1 != frndsList.end()) {
            it = frndsList.erase(it1);
        } else {
            ++it;
        }
    }

    std::vector<string> result(frndsList.begin(), frndsList.end());
    result.erase(std::unique(frndsList.begin(), frndsList.end()),frndsList.end() );


    return result;


}

struct paircomparator
{
    bool operator()(const std::pair<std::string, std::string>&  lhs,
                    const std::pair<std::string, std::string>&  rhs )
    {
        bool result = ((lhs.first == rhs.second) && ( lhs.second == rhs.first) );
        return  !result;
    }
};

int ds()
{
    std::string str = "ABCADC";
    findLongestUniqueSubstring(str);


   /*
    std::vector<string> s = { "A,B","B,C", "D,E", "E,F", "D,C", "A,B", "C,D"};
    compareFriends(s);
    std::string str1 = "BC";
    std::string str2 = "BANGALORE";
    std::vector<std::string>  x = processStrings(str1, str2);
    */



    // findLongestUniqueSubstring(str);
    return 0;
}
