#include "stub.h"
template <typename T1, typename T2>
struct greater_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};
int ewjoghweqjbg()
{
    string in_line;
    map<char,int> mymap;
    getline(cin, in_line);
    int str_length = in_line.length();

    for(int i = 0; i <str_length; ++i )
    {
        mymap[in_line.at(i)]++;
    }
    vector<pair<char, int> > mapcopy(mymap.begin(), mymap.end());
    sort(mapcopy.begin(), mapcopy.end(),greater_second<char, int>());
    cout << "\n Max frequent Char:" << mapcopy.at(0).first <<mapcopy.at(0).second << " times";
    return 0;
}
