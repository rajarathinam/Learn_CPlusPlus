#include "stub.h"
#include <stack>
#include <climits>
class InfixEvaluator
{
public:
	InfixEvaluator()
	{
		d_infix_expression =  "";
	   d_result = 0;
	}
	
    bool isoperator(char c)
	{
		if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		{
			return true;
		}
		return false;
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
	int priority(char optr)
	{
		switch(optr)
		{
		case '*':
		case '/':
				return 2;

		case '+':
		case '-':
			return 1;
		default:
			return 0;
		}
	}
	 void get_infix_expression(const string& c_sting)
	 {
		d_infix_expression = c_sting;
	 }
	 void display_result()
	 {
		 cout<<"\nResult:"<<d_result;
	 }
	 void evaluate()
	 {
		if(!d_infix_expression.empty())
		{
			for(unsigned int i = 0;i<d_infix_expression.length(); i++)
			{
				char ch = d_infix_expression.at(i);
				if(!isoperator(ch))
				{
					d_operand_stack.push(ch -'0');
				}
				else
				{
					while(!d_operator_stack.empty() && priority(ch) <= priority(d_operator_stack.top()))
					{
						 int num2 = d_operand_stack.top();
						 d_operand_stack.pop();
						  int num1 = d_operand_stack.top();
						 d_operand_stack.pop();
						 int result = operation(num1,num2,ch);
				     	d_operand_stack.push(result);							 
					}
					d_operator_stack.push(ch);
				}
			}
			while(!d_operator_stack.empty())
					{
						 int num2 = d_operand_stack.top();
						 d_operand_stack.pop();
						  int num1 = d_operand_stack.top();
						 d_operand_stack.pop();
						 int result = operation(num1,num2,d_operator_stack.top());
						 d_operator_stack.pop();
				     	d_operand_stack.push(result);							 
					}

		}
		d_result = d_operand_stack.top();
	 }

private:
	stack<int> d_operand_stack;
	stack<char> d_operator_stack;
	string d_infix_expression;
	int d_result;
};

int weqkoj()
{
	InfixEvaluator obj_InfixEvaluator;
	obj_InfixEvaluator.get_infix_expression("4+5*3");
	obj_InfixEvaluator.evaluate();
	obj_InfixEvaluator.display_result();
	
	cout<<"\n";
	return 0;
}

