
#include "stub.h"
/*
struct Node
{
  int  minValue;
  int  Value;
  Node *next;
};
class MinStack
{
public:
	MinStack();
	void push(int);
	int pop();
	int getMinValue();
private:
	Node *topNode;
};

MinStack::MinStack()
{
	topNode = NULL;
}
void MinStack::push(int x)
{
	
	Node *newNode = new Node();
	newNode->Value = x;
	newNode->next = NULL;

	if(NULL == topNode)
	{
		newNode->minValue = x;
		topNode = newNode;

	}
	else
	{
		newNode->minValue = newNode->Value <  topNode->minValue ? newNode->Value : topNode->minValue; 
		newNode->next = topNode;
		topNode = newNode;
	}
	
}

int MinStack::pop()
{
	if( NULL == topNode)
	{
		cout<<"Stack is Empty\n";
		
	}
	else
	{
	int temp = topNode->Value;
	topNode = topNode->next;
	return temp;
	}


}
int MinStack::getMinValue()
{
	if(topNode)
	{
		return (topNode->minValue);
	}
}


int edafaesfa()
{
	MinStack s;
	s.push(10);
	s.push(1);
	s.push(2);
	s.push(20);
	s.push(10);
	cout<<s.getMinValue()<<"\n";
	cout<<s.pop()<<endl;

	return 0;
}
*/

/*
struct Node{

int _element;

int _currentMinElement;

Node *next;

Node()

{

_element = 0;

_currentMinElement = 0;

}

};



class MyStack{

Node *topNode;

int _noOfElements;

public:

void push(int elem);

int pop();

bool getCurrentMinElement(int &elem);

bool top(int &elem);

MyStack()
{

topNode = NULL;

_noOfElements = 0;

}

~MyStack(){

int cnt = 0;

while(topNode)

{

pop();

}

}

};



void MyStack::push(int elem)

{

Node *node = new Node();

node->_element = elem;

int x = 0;

node->_currentMinElement = elem;

if(getCurrentMinElement(x))

{

if(x < elem)

{

node->_currentMinElement = x;

}

}

node->next = topNode;

topNode = node;

_noOfElements++;

}



int MyStack::pop()

{

if(!topNode && !_noOfElements)

return -1;



Node *deleteNode = topNode;

int data = deleteNode->_element;

topNode = topNode->next;

delete deleteNode;

_noOfElements--;

return data;

}



bool MyStack::top(int &elem)

{

if(!topNode && !_noOfElements)

return false;



elem = topNode->_element;

return true;

}



bool MyStack::getCurrentMinElement(int &elem)

{

if(!topNode && !_noOfElements)

return false;



elem = topNode->_currentMinElement;

return true;

}

int main()
{
	MyStack s;
	s.push(4);
	s.push(2);
	return 0;
}
*/
