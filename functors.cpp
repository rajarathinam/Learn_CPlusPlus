#include "stub.h"

class MyString
{
public:
    MyString(char* ptr)
    {
        if(ptr == NULL)
        {
            c_str = NULL;
        }
        else
        {
            c_str = new char[strlen(ptr)+1];
            strcpy(c_str,ptr);
        }
    }
    string operator()(char* in)
    {
        string temp(c_str);
        temp += in;
        return temp;
    }
private:
    char* c_str;
};

int hihdwfk()
{


   MyString str("Hello ");
   vector<char*> v;
   v.push_back("VIT");
   v.push_back("Honeywell");
   v.push_back("OpenCV");
   for_each(v.begin(),v.end(),str);
   for(auto item: v)
       cout << item;


    cout << endl;
    return 0;
}
