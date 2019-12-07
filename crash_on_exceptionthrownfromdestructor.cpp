#include "stub.h"

//https://quizbucket.org/what-is-the-output-of-the-following-code-2842
//https://www.toptal.com/c-plus-plus/interview-questions
class A
{
public:
    A(){}
    ~A() {
        std::cout << "In Destructor" << std::endl;
        throw (42);
    }
};
/*
template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};


template <class A, class B>
bool IsSameClass() {
    return is_same<A, B>::value;
}
*/

template<typename D, typename B>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };

    static Yes Test( B* );
    static No Test( ... );
public:
    enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };

};


template <class C, class P>
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}

template<typename B, typename D>
inline bool instanceof(const D*) {
   return is_base_of<B, D>::value;
}




void F(int* A, int* B, int N) {
    // Set prod to the neutral multiplication element
    int prod = 1;

    for (int i = 0; i < N; ++i) {
        // For element "i" set B[i] to A[0] * ... * A[i - 1]
        B[i] = prod;
        // Multiply with A[i] to set prod to A[0] * ... * A[i]
        prod *= A[i];
    }

    // Reset prod and use it for the right elements
    prod = 1;

    for (int i = N - 1; i >= 0; --i) {
        // For element "i" multiply B[i] with A[i + 1] * ... * A[N - 1]
        B[i] *= prod;
        // Multiply with A[i] to set prod to A[i] * ... * A[N - 1]
        prod *= A[i];
    }
}


template <class T, class U>
void f(T arg1, U arg2)
{

}

template <>
void f(int arg1, int arg2)
{
    //...
}

class Raja1
{
public:
    Raja1()
    {
      m_p = new int;
      *m_p = 99;
    }
    ~Raja1()
    {
        std::cout << "Destructor called \n";
        delete m_p;
    }
    void display()
    {
      std::cout << *m_p << std::endl;
    }
private:
    int *m_p;
};

class A1
{
public:
     A1(){ cout <<"1\n";}
    // A1(const A &obj){ cout <<"2\n";}
};

class B1: virtual A1
{
public:
    B1(){cout <<"3\n";}
   // B1(const B1 & obj){cout<<"4\n";}
};

class C1: virtual A1
{
public:
   C1(){cout<<"5\n";}
  // C1(const C1 & obj){cout <<"6\n";}
};

class D1:B1,C1
{
public:
    D1(){cout<<"7\n";}
    D1(const D1 & obj){cout <<"8\n";}
};

int shusjodwjqd()
{
   D1 d1;
   D1 d(d1);
}
