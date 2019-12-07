#include "stub.h"
#define ALPHABETS_COUNT 26


class Trie
{
public:
    typedef struct Trie_Node
    {
       char ch_value;
       vector<Trie_Node*> mChildren;
    }T_NODE;

    Trie();

    void addWord(const string& s);
    T_NODE* findChild(const char& ch);
private:

    T_NODE* root;

};
Trie::Trie():root(new T_NODE){}

void Trie::addWord(const string &s)
{
   T_NODE* current = root;
   for(auto x : s)
   {
       T_NODE* result = findChild(x);
       T_NODE* newnode = new T_NODE;
       newnode->ch_value = x;
       if( NULL == result)
       {

           current->mChildren.push_back(newnode);
       }
       else
       {
           current = result;
       }
   }
}

Trie::T_NODE* Trie::findChild(const char &ch)
{
    T_NODE* current = root;

    for(int i = 0; i < current->mChildren.size(); ++i)
    {
        if(current->mChildren[i]->ch_value == ch)
        {
            return current->mChildren[i];
        }
    }
    return NULL;


}

int dee()
{
    Trie *trie = new Trie;
    trie->addWord("Raja");
    trie->addWord("Rani");
    cout << '\n';
    return 0;
}

