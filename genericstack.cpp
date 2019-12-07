#include"stub.h"

template<class T>
class Stack
{

	private:
		signed int top;
		T arr[2];
	public:
		Stack();
		void push(T const& element);
		T pop();

		bool IsEmpty()
		{
			if(top < 0)
				{

					return true;
				}
				else
				{
					return false;
				}
		}
		bool IsFull()
		{
			if(top>=1)
				{
					return true;
				}
				else
				{
					return false;
				}

		}
		void reverse();
		void sort();
};
template<class T>
void Stack<T>::reverse()
{
  if(!IsEmpty())
  {
      int temp = pop();
	  reverse();
	  push(temp);
  }
}
template<class T>
Stack<T>::Stack()
{
	top=-1;
}

template<class T>
void Stack<T>::push(T const& element)
{
	if(IsFull())
	{
		cout<<"\n Stack is Full\n";
		return;
	}
	++top;
	arr[top]=element;
}

template<class T>
T Stack<T>::pop()
{
	if(!IsEmpty())
	{
		return arr[top--];
	}
	else
	{
		cout<<"\n Stack is Empty\n";
	}

}
template<class T>
void Stack<T>::sort()
{
    //stack<
 
}


int wddww()
{
	return 0;
}
