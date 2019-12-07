#include "stub.h"
/*void reverseword(char* begin, char* end)
{
   char temp;
   while(begin < end)
   {
       temp = *begin;
       *begin = *end;
       *end = temp;
       ++begin;
       --end;
   }
}

void processstring(std::string& str)
{

    char* source = const_cast<char*>(str.c_str());
    char* word_begin = source;
    char* temp = source;
    while(*temp)
    {
        temp++;
        if( *temp == '\0')
        {
           reverseword(word_begin, temp-1);
        }else if( *temp == ' ')
        {
           reverseword(word_begin, temp-1);
           word_begin = temp + 1;
        }
    }
    reverseword(source, temp - 1);
    std::cout << source << '\n';




}


int main() {
        std::string str = "ASML GE";
        processstring(str);
        std::cout << str << '\n';

    return 0;
}
*/
/*

class LRUCache
{
public:
    LRUCache(int cachecapacity):m_cachecapacity(cachecapacity) {}
    void set(int key, int value)
    {
        if (m_cachemap.find(key) != m_cachemap.end())
        {
           // cachelist.erase()
           // cachelist.p
        }
    }
    int get(int key)
    {
       if (m_cachemap.find(key) != m_cachemap.end())
       {
           std::list<int>::iterator it = m_cachemap[key];
           return (*it);
       } else {
           return -1;
       }
    }
private:
    std::unordered_map<int, std::list<int>::iterator > m_cachemap;
    std::list<int> cachelist;

    int m_cachecapacity;
};
*/
