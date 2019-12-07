#include "stub.h"
#include <stack>
class Postfix_Evaluator
{
public:
	Postfix_Evaluator()
	{
		d_postfix_expression = "";
		d_result = 0;
	}

	int operation(int a,int b,char opr)
	{
			switch(opr) 
			{
				case '+':return a+b;
				case '-':return a-b;
				case '*':return a*b;
				case '/':return a/b;
				default: return 0;
			}
	}
	bool isoperator(char c)
{
	if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
	{
		return true;
	}
	return false;
}

	 void get_postfix_expression(const string& c_sting)
	 {
		d_postfix_expression = c_sting;
	 }
	 void display_result()
	 {
		 cout<<"\nResult:"<<d_result;
	 }
	 void evaluate()
	 {
		if(!d_postfix_expression.empty())
		{
			for(unsigned int i =0;i<d_postfix_expression.length(); i++)
			{
				char ch = d_postfix_expression.at(i);
				if(isdigit(d_postfix_expression.at(i)))
				{
					d_stack.push(ch - '0');
				}
				if(isoperator(ch))
				{
					int num2 =  d_stack.top();
					d_stack.pop();
				    int num1 =  d_stack.top();
					d_stack.pop();
					int result = operation(num1,num2,ch);
					d_stack.push(result);
				}
			}
		}
		d_result = d_stack.top();
	 }

private:
	stack<int> d_stack;
	string d_postfix_expression;
	int d_result;
};

int eflprolgr()
{
	Postfix_Evaluator obj_Postfix_Evaluator;
	obj_Postfix_Evaluator.get_postfix_expression("45+6*9/");
	obj_Postfix_Evaluator.evaluate();
	obj_Postfix_Evaluator.display_result();
	
	cout<<"\n";
	return 0;
}