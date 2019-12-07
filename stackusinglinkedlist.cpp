
#include<iostream>
#include<new>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node LIST;
LIST *top=NULL;

void push(int num)
{
	LIST *temp=new(nothrow) LIST ;
	if(temp == NULL)
	{
		cout<<"\nUnable to allocate Memory\n";
	}
	else
	{
		temp->data=num;
		temp->next=top;
		top=temp;
	}

}

int pop()
{
	LIST *temp;
	int item;

	if(top== NULL)
	{
		cout<<"\nStack is Empty\n";
		return NULL;
	}
	temp=top;
	item=temp->data;
	top=top->next;
	delete temp;
	return item;
}
void display()
{
	LIST *top1=top;
	while(top1!=NULL)
	{
		cout<<top1->data<<" ";
		top1=top1->next;
	}
}

int wduoedkj()
{
	push(10);
	push(20);
	push(30);
	cout<<pop();
	cout<<endl;
	display();
	return 0;

}
