#include<iostream>
#include<string.h>
#include "book.h"
using namespace std;
class Bar
{

  string fname;
  string lname;
public:
  Bar(string x, string y ):fname(x),lname(y)
  {
  }
};



string& GetM2(Bar* pBar)
{
  string* p = reinterpret_cast<string*>(pBar);
 // p+=sizeof();
  return *(reinterpret_cast<string*>(p));
}
int ue3hueh()
{
 Bar obj("RAJA","Rathinam");
 //cout<<GetM2(&obj)<<endl;
 return 0;
}

