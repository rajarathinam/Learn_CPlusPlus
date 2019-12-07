#include "stub.h"


class LinkedList;


Node* sortedMerge(Node* node1, Node* node2)
{

    if( NULL == node1)
    {
        return node2;

    }
    if(NULL == node2)
    {
        return node1;
    }

    if( node1->data <=  node2->data)
    {
        node1->next = sortedMerge(node1->next,node2);
                return node1;
    }
    else
    {
        node2->next = sortedMerge(node2->next,node1);
                return node2;
    }




}
class LinkedList
{
public:
    LinkedList()
    {
        m_head = NULL;
    }
    ~LinkedList()
    {
        while(m_head)
        {
            Node* temp = m_head;
            delete  temp;
            m_head = m_head->next;
        }
    }
    void insert(int t_data)
    {
         Node* newnode = new Node(t_data);

        if( NULL == m_head)
        {
            m_head = newnode;
        }
        else
        {

            Node *temp = m_head;
            while(temp && temp->next)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }


    }
    void sortedInsert(int t_data)
    {
         Node* newnode = new Node(t_data);

        if( NULL == m_head || newnode->data < m_head->data)
        {
            newnode->next = m_head;
            m_head = newnode;
        }
        else
        {
            Node *current = m_head;
            while(current->next && current->next->data < newnode->data)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }

    }
    bool isPalindromewithStack()
    {
        if( NULL == m_head || NULL == m_head->next)
        {
            return true;
        }
        stack<Node*> mystack;
        Node* current = m_head;
        while(current)
        {
           mystack.push(current);
           current = current->next;
        }
        Node* temp = m_head;
        while(temp)
        {
            if(temp->data != mystack.top()->data)
            {
                return  false;
            }
            mystack.pop();
            temp = temp->next;
        }
        return true;


    }



   void display()
   {
       if( NULL == m_head)
       {
           cout << "\n List is Empty";
           return;
       }
       Node* current = m_head;
       while(current)
          {
           cout << current->data << "->";
           current = current->next;
         }

   }
    Node* m_head;

};



int wswmain()
{


 LinkedList list1;
 LinkedList list2;
 list1.insert(2);
 list1.insert(3);
 list1.insert(6);
 list2.insert(1);
 list2.insert(4);
 list2.insert(5);
/*
 LinkedList *mergedList;
 mergedList->m_head = sortedMerge(list1.m_head,list2.m_head);
 mergedList->display();
 */




 if(list1.isPalindromewithStack())
 {
     cout << "\nPalindrome";
 }
 else
 {
     cout << "\n Not a Palindrome";
 }



    cout << endl;
    return 0;
}
