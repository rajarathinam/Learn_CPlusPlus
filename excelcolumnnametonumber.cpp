#include "stub.h"
int getColumnNumberFromColumnName(const std::string& str)
{
    int result = 0;
   if(!str.empty()) {

       for(auto ch : str)
       {
          result *= 26;
          result += ch - 'A' + 1;
       }
   }
   return result;
}

std::string getColumnNameFromNumber(int num)
{
    std::string result = "";
    if( num > 1)
    {
        while (num > 0)
        {
            int remainder = num % 26;
            if(remainder == 0)
            {
                result.push_back('Z');
                num = (num /26) - 1;
            } else {
                char ch = 'A' + remainder - 1;
                result.push_back(ch);
                num = (num /26);

            }
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}



 class Aircraft
 {
 public:
     Aircraft(std::string name) :m_name(name)
     {

     }
     ~Aircraft()
     {
         std::cout << "~Aircraft() called" << std::endl;
     }
     std::shared_ptr<Aircraft> m_other;
 private:
     std::string m_name;

 };

int snjks() {
    std::shared_ptr<Aircraft> sp1 = std::make_shared<Aircraft>("Boeing");
    std::shared_ptr<Aircraft> sp2 = std::make_shared<Aircraft>("E170");
    sp1->m_other = sp2;
    sp2->m_other = sp1;


  return 0;
}
