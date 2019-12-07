#include <array>
#include "stub.h"

int zwdkl3rqkomain()
{
array<int,6>   arr  = {{900,  940, 950,  1100, 1500, 1800}};
array<int,6>   dep = {{910, 1200, 1120, 1130, 1900, 2000}};
map<int,string> mymap;
 int current_required_platforms = 0;
 vector<int> buffer;
for(auto&& x : arr)
{
    mymap.insert(make_pair(x,"A"));
}
for(auto&& x : dep)
{
    mymap.insert(make_pair(x,"D"));
}

for( auto  x: mymap)
{

 if( x.second == "A")
 {
current_required_platforms++;

 }
 if( x.second == "D")
 {
     current_required_platforms--;


 }
 buffer.push_back(current_required_platforms);
}
make_heap(buffer.begin(),buffer.end());
cout << "Max Value:" << buffer.front();
    return 0;
}
