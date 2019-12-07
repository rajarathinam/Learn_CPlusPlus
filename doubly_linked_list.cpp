#include "stub.h"

typedef struct dllNode
{
	int data;
	struct dllNode *prev;
	struct dllNode *next;
}DLLNODE;

class DLL
{
	 
public:
	DLL()
	{
		head = NULL;
		tail = NULL;
	}
	DLLNODE *head;
	DLLNODE *tail;
	void insert(int);
	void displayfromhead();
	void displayfromtail();

};


void DLL::insert(int num)
{
   DLLNODE *newnode = new DLLNODE;
   newnode->data = num;
   newnode->next = NULL;
   newnode->prev = NULL;

   if( NULL == head)
   {
	   head  = newnode;
	   tail = newnode;
   }
   else
   {
	   DLLNODE* current = head;
	   while( current->next != NULL)
	   {
		   current = current->next;
	   }
	   current->next = newnode;
	   newnode->prev = current;
	   tail = newnode;
   }
   

}

void DLL::displayfromhead()
{
	if( NULL == head)
	{
		cout<<"DLL is Empty\n";
	}
   DLLNODE* current = head;
	while( current != NULL)
	{
		cout<<current->data<<"->";
		current = current->next;
	}
	cout<<"\n";
}
void DLL::displayfromtail()
{
	if( NULL == tail)
	{
		cout<<"DLL is Empty\n";
	}
   DLLNODE* current = tail;
	while( current != NULL)
	{
		cout<<current->data<<"->";
		current = current->prev;
	}
	cout<<"\n";
}

int w333()
{
	DLL *dlist = new DLL;
	dlist->insert(10);
	dlist->insert(20);
	dlist->displayfromhead();
	dlist->displayfromtail();
	return 0;
}