#include "stub.h"

class Queue
{
public:
    explicit Queue(int x);
    void push(int x);
    void pop();
    int peek();
    ~Queue();

private:
    vector<int> qv;

};

Queue::Queue(int x)
{
    qv.push_back(x);
}

void Queue::push(int x)
{
    qv.push_back(x);
}

void Queue::pop()
{
    qv.erase(qv.begin());
}
int Queue::peek()
{
    if(!qv.empty())
        {
            return qv.front();
        }
    {
        cout << "\nQueue is Empty";
    }
}

void reveresCharacters(string& s)
{
    if(!s.empty())
        {
            reverse(s.begin(),s.end());
        }
}

int qqq()
{
    Queue* myqueue = new Queue(10);
    myqueue->push(20);
    myqueue->push(30);
    cout <<"Before Pop():" << myqueue->peek();
    myqueue->pop();
    cout << "After Pop():" << myqueue->peek();
    cout << "\n";
    return 0;
}
