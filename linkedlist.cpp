#include "linkedlist.h"
template<class T>
LinkedList<T>::LinkedList()
{
    first = nullptr;
    last = nullptr;
}
template<class T>
void LinkedList<T>::insertAtBack(T element)
{
    NODE<T>* newnode = new NODE<T>(element);

    if(first == nullptr && last == nullptr)
    {
        first = last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
}
template<class T>
void LinkedList<T>::insertAtFront(T element)
{
    NODE<T> *temp = first;
    if( nullptr == temp)
    {
         first = last = new NODE<T>(element);
    }
    else
    {
        first = new NODE<T>(element);
        first->next = temp;

    }
}
template<class T>
void LinkedList<T>::insertBefore(T element)
{
   NODE<T>* temp = first;
   while( temp )
   {

   }
}
template<class T>
bool LinkedList<T>::isElementPresent(T element)
{
   bool result = false;
   NODE<T>* temp = first;
   while(temp)
   {
       if(element == temp->data)
       {
           result = true;
           break;
       }
       temp = temp->next;
   }
   return result;
}

template<class T>
NODE<T> *LinkedList<T>::getNodeBeforeElementNode(T element)
{
    NODE<T>* result = nullptr;
    if(nullptr == first)
        return result;
    if(element == first->data)
    {
        result = first;
    }
    else
    {
        NODE<T>* temp = first;
        while(temp)
        {
            if( element == temp->data)
            {
                result = temp;
            }
            temp = temp->next;
        }

    }




}

template<class T>
void LinkedList<T>::display()
{
    NODE<T>* temp = first;
    if(nullptr == temp)
    {
        cout << " ";
    }
    else if(nullptr == temp->next)
    {
        cout << temp->data;
    }
    else
    {
        while(nullptr != temp )
        {
            cout << temp->data;
            temp = temp->next;
            cout << " -> ";
        }
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    NODE<T>* temp  = first;
     while(nullptr != temp)
     {
         temp = temp->next;
         delete (first);
         first = temp;
     }
}
