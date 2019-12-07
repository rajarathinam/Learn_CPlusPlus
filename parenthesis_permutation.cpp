#include "stub.h"
# define MAX_SIZE 100
vector<string> result;
 
void _printParenthesis(int pos, int n, int open, int close);
 
/* Wrapper over _printParenthesis()*/
void printParenthesis(int n)
{
  if(n > 0)
     _printParenthesis(0, n, 0, 0);
  return;
}    

void _printParenthesis(int pos, int n, int open, int close)
{
  static char str[MAX_SIZE];    
 
  if(close == n)
  {
    //printf("%s \n", str);
	result.push_back(str);
    return;
  }
  else
  {
    if(open > close) {
        str[pos] = '}';
        _printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '{';
       _printParenthesis(pos+1, n, open+1, close);
    }
  }
}
 
/* driver program to test above functions */
int eioer()
{
  // int n = 2;
  printParenthesis(3);
  vector<string>::iterator it;
  for(it = result.begin(); it != result.end(); ++it)
  {
	  cout<<*it<<endl;
  }
  getchar();
  return 0;
}
