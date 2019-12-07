#include "stub.h"
class A1 {};

class B1 : public A1 {};

class C1 {};

//is_same
template<typename T, typename U>
struct IsSameClassUtil
{
    const static bool value = false;
};


template<typename T>
struct IsSameClassUtil<T,T>
{
    const static bool value = true;
};

template<typename A, typename B>
bool IsSameClass()
{
     return IsSameClassUtil<A, B>::value;
}


//is_base_of or isDerivedFrom

template<class Derived, class Base>
struct IsDerivedFromHelper
{
   class No {};
   class Yes { No no[3];};
   static Yes Test (Base*){}
   static No Test (...) {}

   static const bool value = ( sizeof (Yes) ==  sizeof (Test(static_cast<Derived*>(nullptr))));
};

template<class D, class B>
bool isDerivedFrom()
{
    return IsDerivedFromHelper<D,B>::value;
}


inline size_t align(size_t n) {
  size_t alignedSize =  (n + sizeof(intptr_t) - 1) & ~(sizeof(intptr_t) - 1);
  return alignedSize;
}

int vhg()
{
    size_t size = align(6);

    std::vector<int> v{1,2,3,4,5,6,7};
    std::cout << "Hello" << std::endl;
    return 0;
}
