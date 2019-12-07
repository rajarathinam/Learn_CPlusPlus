#include "stub.h"
#include<stack>

class AdvancedStack
{
public:
	AdvancedStack()
	{

	}
	void push(int);
    int pop();
	int min();

	stack<int> d_mainstack;
	stack<int> d_minstack;

};

void AdvancedStack::push(int data)
{
	
		d_mainstack.push(data);
		if( d_minstack.empty() || d_minstack.top() >= data)
		{
		d_minstack.push(data);
		}
		else
		{
			//d_minstack.push(d_minstack.top());
		}
	
}
int AdvancedStack::min()
{
	if( !d_minstack.empty())
	{
		return (d_minstack.top());
	}
}
int AdvancedStack::pop()
{
	if( !d_mainstack.empty())
	{
		int temp = d_mainstack.top();
		d_mainstack.pop();
		if(d_minstack.top() == temp)
		{
			d_minstack.pop();
		}
		return temp;
	}
}
int dnmoirf()
{
	AdvancedStack st;
	st.push(2);
	st.push(6);
	st.push(4);
	st.push(1);
	st.push(5);
	cout<<st.min()<<"\n";
	st.pop();
	cout<<st.min()<<"\n";
	st.pop();
	cout<<st.min()<<"\n";

	
    
	
	return 0;
}