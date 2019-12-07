#include "stub.h"

template<class T, size_t N>
size_t arraySize(T(&)[N])
{
    return N;
}
void leftRotateByOne(int arr[], int size)
{
    int lastElement = arr[size - 1];
    int i;
    for (i = 0; i < size - 1;++i) {
        std::cout << "i = " << i;
        int temp = arr[i];
         arr[i+1] = temp;
    }
    arr[size - 1] = arr[i];
    arr[0] = lastElement;

         }
struct ciCompare
{
public:
    bool operator() (const std::string& obj1, const std::string& obj2)
    {
        return  (obj1.compare(obj2) == 0);
    }
};

struct MyFunction
{
public:
    int operator() (int x)
    {
        return ( x + 10);
    }
};

std::list<void*> allocatedList;
/*
void* operator new(size_t size)
{
    std::cout << "operator new called " << size <<  std::endl;
    void *p = malloc(size);

    if(p)
    {
        allocatedList.push_back(p);
    }

    return  p;
}
*/

class Raja
{
public:
    Raja(int x)
    {
        m_x = x;
        std::cout << "Constructor" << std::endl;
    }
    ~Raja()
    {
        std::cout << "Destructor" << std::endl;
    }
private:
    int m_x;
};

struct Deletor
{
public:
    template<class T>
    void operator()(const T *ptr) const
    {
        delete ptr;
    }
};

int  majakjkain()
{
   std::vector<Raja*> v1;
   for (auto i = 0; i < 5; ++i) {
       v1.push_back((new Raja(i)));
   }
    std::for_each(v1.begin(), v1.end(), Deletor());





/*
    int arr[] = { 1,2,3};
    int n  = arraySize(arr);

    for (auto i = 0;i < 1; ++i) {
        leftRotateByOne(arr, n);

    }

    for(auto i : arr)
    {
        std::cout << i << " ";
    }
    */
    std::cout << '\n';
    return 0;
}
