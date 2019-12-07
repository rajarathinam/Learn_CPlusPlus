#include "stub.h"



int wwsee()
{
   string  str = "RajaRathinama";

   map<char,int> mymap;

   for(int i = 0;  i < str.length(); ++i)
   {
       mymap[str.at(i)]++;
   }

   for(auto item: mymap)
   {
       cout << item.first << " : " << item.second <<" times\n";
   }



    cout << '\n';
    return 0;
}
