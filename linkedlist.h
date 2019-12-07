#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace  std;
template<class T>
struct NODE
{
    NODE<T>(T ele)
    {
        data = ele;
        next = nullptr;
    }

    T data;
    NODE<T>* next;
};

template<class T>
class LinkedList
{
public:
    LinkedList();
    void insertAtBack(T element);
    void insertAtFront(T element);
    void insertBefore(T element);
    bool isElementPresent(T element);
    NODE<T>* getNodeBeforeElementNode(T element);
    void display();
    ~LinkedList();
private:
    NODE<T>* first;
    NODE<T>* last;

};

#endif // LINKEDLIST_H
