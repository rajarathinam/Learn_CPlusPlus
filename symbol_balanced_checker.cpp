#include "stub.h"
#include<stack>

class SymbolBalanceChecker
{
public:
	SymbolBalanceChecker(char* ptr=NULL)
	{
		sequence = new  char[strlen(ptr) + 1];
		strcpy(sequence,ptr);
	}
	bool isBalanced()
	{
		if(NULL == sequence)
		{
			return true;
		}
		bool result = true;
		while(*sequence)
		{
			if(*sequence == '(') 
			{
				Stack.push(*sequence);
			}
			if(*sequence == ')') 
			{ if( !Stack.empty())
			{
				char temp = Stack.top();
				Stack.pop();
				if( temp!= '(' )
				{
					result = false;
				return result;
				}
			}
			else
			{

			result = false;
		}
			}
			sequence++;

		}
		if( !Stack.empty())
		{
			result = false;
		}
		return result;
	}

	

private:
	char *sequence;
	stack<char> Stack;

};

int eeee()
{
	SymbolBalanceChecker obj("(((A+B)+C)+D))");
	if(obj.isBalanced())
	{
		cout<<"Yes, It is Balanced\n";
	}
	else
	{
		cout<<"NO, It is not Balanced\n";
	}
		return 0;
}

