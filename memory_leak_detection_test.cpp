#include<iostream>

using namespace std;

class A {
public:
    void fun()
    { cout<<"\n A::fun() called ";}
};

class B {
public:
    void fun()
    { cout<<"\n B::fun() called "; }
};

class C: public A, public B {
public:
    void fun()
    { cout<<"\n C::fun() called "; }
};

int snksjs()
{
C c; // An object of class C
A *b = &c; // A pointer of type B* pointing to c
b->fun(); // this line prints "C::fun() called"
std::cout << '\n';
return 0;
}

/*
 * #include <stdlib.h>
#include "memory_leak_detector.h"


int main()
  {



      char * ptr1;
    int * ptr2;
    float * ptr3;

    atexit(report_mem_leak);

    ptr1 = (char *) malloc (10); // allocating 10 bytes
    ptr2 = (int *) calloc (10, sizeof(int)); 	// allocating 40 bytes
                    // let sizeof int =  4 bytes)
    ptr3 = (float *) calloc (15, sizeof(float)); // allocating 60 bytes

    free(ptr2);

    return 0;
  }

  */
