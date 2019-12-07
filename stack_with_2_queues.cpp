#include "stub.h"
class MyStack
{
public:
    void push(int);
    int pop();
    bool isEmpty();
private:
    queue<int> q1;
    queue<int> q2;
};

int wsefedveg()
{

    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.pop();
    cout << s.pop();

    cout << '\n';
    return 0;
}


void MyStack::push(int x)
{
    q1.push(x);
}

int MyStack::pop()
{
    while(  q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int popped_value = q1.front();
    q1.pop();
    swap(q1,q2);
    return popped_value;
}
