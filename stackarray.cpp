#include <iostream>
using namespace  std;


const int INITIAL_STACK_TOP_VALUE = 0;

class StackArray
{
public:
    StackArray(int size)
    {
        arr = new int[size];
        top = -1;
        capacity = size - 1;
    }
    bool isEmpty(){
        if(top < 0) {
            return  true;
        } else {
            return false;
        }
    }
    bool isFull()
    {
        if (top == capacity)
        {
            return true;
        } else {
            return false;
        }

    }

    void push(int value)
    {
        if(!isFull()) {
            arr[++top] = value;
        } else {
            std::cout << "Stack is Full\n";
        }

    }

    int  pop(int value)
    {
        if(!isEmpty()) {
            return arr[top--];
        } else {
            std::cout << "Stack is Empty\n";
        }

    }

    int peek()
    {

        if(!isEmpty()) {
           return arr[top];
        } else {
            std::cout << "Stack is Empty\n";
        }
    }


private:
    int *arr;
    int top;
    int capacity;
};

#include <sstream>
#include <stack>
#include <map>

class Employee
{
public:
    Employee(int value)
    {
        m_array = new int;
        *m_array = value;

    }

    Employee(const Employee& rhs)
    {
        m_array = new int;
        std::cout << "In Copy constructor " << &this->m_array << '\n';
        std::cout << "In Copy constructor " << &this->m_array << '\n';
        std::memcpy(this->m_array, rhs.m_array, sizeof (int) );
    }


    friend void swap (Employee& obj1, Employee& obj2)
    {
        std::cout << "obj1->m_array " << &obj1.m_array << '\n';
        std::cout << "obj2->m_array " << &obj2.m_array << '\n';

        std::swap(obj1.m_array, obj2.m_array);

        std::cout << "obj1->m_array " << &obj1.m_array << '\n';
        std::cout << "obj2->m_array " << &obj2.m_array << '\n';

    }

    Employee& operator=(Employee rhs)
    {/*
        if (this != &rhs)
        {
            delete[] m_array;
            m_array = new int[rhs.m_size];
            m_size = rhs.m_size;
            std::memcpy(this->m_array, rhs.m_array, sizeof (int) * rhs.m_size);
        }
        */
        swap(*this, rhs);

        return *this;
    }


    void display()
    {

        std::cout << *m_array << '\n';
    }
    ~Employee() {
        delete m_array;
    }


public:
    int *m_array;
    int m_size;

};

int snjchisck()
{
    Employee emp1(5);
    emp1.display();
    Employee emp2(2);
    emp2 = emp1;
    emp2.display();
    /*

    std::stack<char> mystack;
    std::string str = "Raja";
    for(auto i = 0; i < str.length(); ++i)
    {
        mystack.push(str[i]);
    }


    StackArray stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    */
    std::cout << '\n';
    return 0;
}
