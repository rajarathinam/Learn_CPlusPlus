#include "stub.h"
#include<stack>

class MyQueue
{
	
public:
	void enqueue(int item)
	{
		stack1.push(item);
	}
	int dequeue()
	{
		int temp,result;
		if(!stack2.empty())
		{
			temp = stack2.top();
		    stack2.pop();
		}
		else
		{
			while( !stack1.empty())
			{
				
				temp = stack1.top();
		        stack1.pop();
				stack2.push(temp);
			}
		}

		result = stack2.top();
		        stack2.pop();
				return result;
	}
private:
	 stack<int> stack1;
     stack<int> stack2;
};


int wdww()
{

	MyQueue q;
	q.enqueue(10);
	q.enqueue(20);
	cout<<q.dequeue()<<"\n";
	q.enqueue(30);
	cout<<"\n";
	return 0;
}