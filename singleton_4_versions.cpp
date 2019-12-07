#include "stub.h"

class simpleSingleton
{
    simpleSingleton()
    {

    }
    /*
    simpleSingleton(const simpleSingleton&)
    {

    }
    simpleSingleton& operator=(const simpleSingleton&)
    {

    }

    ~simpleSingleton()
    {
    }
    */



    static simpleSingleton* _pInstance;

public:


    static simpleSingleton* getInstance()
    {
        if(!_pInstance)
        {
            _pInstance = new simpleSingleton();
        }

        return _pInstance;
    }

    void demo()
    {
        cout<<"\nAddress of this Instance:"<<this;
        std::cout << "\nsimple singleton # next - your code ..." << std::endl;
    }
};

simpleSingleton* simpleSingleton::_pInstance = nullptr;

int maqaqqin()
{


    // Version 1
    simpleSingleton * p = simpleSingleton::getInstance();	// cache instance pointer
    p->demo();

    // Version 2
    simpleSingleton::getInstance()->demo();

    simpleSingleton ob2(*p);          // copy constructor
    ob2.demo();

    simpleSingleton ob3 = ob2;        // copy constructor
    ob3.demo();


    cout << endl;
    return 0;
}
