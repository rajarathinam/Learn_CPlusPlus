#include "stub.h"
class Singleton {
public:
    static Singleton* getInstance() {
        if (NULL == _instance) {
            _instance = new Singleton();
        }
        _referenceCount++;
        return _instance;
    }

    static void releaseInstance() {
        _referenceCount--;
        if ((0 == _referenceCount) && (NULL != _instance)) {
            delete _instance;
            _instance = NULL;
        }
    }

private:
    // default constructor
    Singleton() {
    }

    // default destructor
    ~Singleton() {
    }

    // copy constructor
    Singleton(const Singleton&) {
    }

    // assignment operator
    Singleton& operator=(const Singleton&) {
        return *this;
    }

    // the single instance of the object
    static Singleton* _instance;

    // the count of references
    static int _referenceCount;
};

int Singleton::_referenceCount = 0;
Singleton* Singleton::_instance = NULL;
