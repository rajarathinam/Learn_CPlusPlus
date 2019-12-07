#include "stub.h"
bool isDivisibleByAAndB(const string& str, int a, int b)
{
   size_t len = str.length();
   bool result = false;
   if(len > 1 && ( (a != 0)  && (b != 0)))
   {
   for(size_t i = 1;i < len; ++i)
   {
      /*
      int num1 =  boost::lexical_cast<int>(str.substr(0,i));
      int num2 =  boost::lexical_cast<int>(str.substr(i,len));
      */
       int num1 =  stoi(str.substr(0,i));
       int num2 =  stoi(str.substr(i,len));

      if ( (num1 % a) == 0 && (num2 % b) == 0 )
      {
          result = true;
          break;
      }
   }
   }
   return result;
}

int enjkvj()
{
    string str = "123";
    int a = 3;
    int b =03;

    if(isDivisibleByAAndB(str,a,b))
    {
        cout << "Divisible\n";
    }else {
        cout << "Not Divisible\n";
    }



    cout << '\n';
    return 0;
}
