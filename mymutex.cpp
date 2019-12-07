
#include "stub.h"

class MyMutex
{
public:
    MyMutex()
    {
       mutex = false;
    }
    bool test_and_set(bool &mutex) {
       bool tmp=mutex;
       mutex = true;
       return tmp;
    }



    void lock(bool &mutex) {
       while(test_and_set(mutex));
    }

    void unlock(bool mutex) {
       mutex = false;
    }

    ~MyMutex()
    {

    }
private:
    bool mutex;
};


int mwewwain()
{
    MyMutex mutex;
    bool state;
state = true;
    mutex.lock(state);
    int x = 0;
    mutex.unlock(state);
    return 0;
}
