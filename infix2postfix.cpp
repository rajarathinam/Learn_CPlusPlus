#include "stub.h"
#include<stack>
class Infix2Postfix
{
public:
	Infix2Postfix()
	{
	string d_infix_expression  = "";
	string d_postfix_expression = "";
	}
	void get_infix_expression(char* p_input)
	{
		d_infix_expression = string(p_input);
	}
	void display_infix_expression()
	{
		cout<<"Infix Expression:"<<d_infix_expression<<"\n";
	}
	void display_postfix_expression()
	{
		cout<<"Postfix Expression:"<<d_postfix_expression<<"\n";
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
	void convert_to_postfix()
	{
		for( unsigned short int i=0;i<d_infix_expression.length();i++)
		{
			if(  isdigit(d_infix_expression.at(i)) || isalpha(d_infix_expression.at(i)))
			{
				d_postfix_expression.push_back(d_infix_expression.at(i));
			}
			if( '(' == d_infix_expression.at(i))
			{
				d_stack.push(d_infix_expression.at(i));
			}
			if( '+' == d_infix_expression.at(i) || '-' == d_infix_expression.at(i) || '*' == d_infix_expression.at(i) || '/' == d_infix_expression.at(i))
			{
				
					
					
						char op = d_stack.top();
						//d_stack.pop();
						while( priority(op) >= priority(d_infix_expression.at(i)))
						{
						d_postfix_expression.push_back(d_stack.top());
						d_stack.pop();
						op = d_stack.top();
					    }
				
				
			
				d_stack.push(d_infix_expression.at(i));
			}
			
			if( ')' == d_infix_expression.at(i))
			{
				char temp = d_stack.top();
				d_stack.pop();
				while( '(' != temp)
				{
					d_postfix_expression.push_back(temp);
					temp = d_stack.top();
					d_stack.pop();
				}
			}
		 }
		
	}
private:
	string d_infix_expression;
	string d_postfix_expression;
	stack<char> d_stack;
};

int efkoekr()
{
	Infix2Postfix obj;
	obj.get_infix_expression("(((a+b)*(c-d))/x)");
	obj.display_infix_expression();
    obj.convert_to_postfix();
	obj.display_postfix_expression();
	return 0;
}