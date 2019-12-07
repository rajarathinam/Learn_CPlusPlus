#include "stub.h"

std::map<int, std::string> mymap =
{
    {0,"0"},
    {1,"1"},
    {2,"ABC"},
    {3,"DEF"},
    {4,"GHI"},
    {5,"JKL"},
    {6,"MNO"},
    {7,"PRS"},
    {8,"TUV"},
    {9,"WXY"},


};

//create a Thing and return a unique_ptr to it:
std::unique_ptr<int> create_Thing(std::unique_ptr<int>& p)
{
std::unique_ptr<int> local_ptr(new int);
*p = 99;
return (std::move(p)); // local_ptr will surrender ownership
}
int ajka()
{
    std::unique_ptr<int> p(new int);
    *p = 10;
    std::unique_ptr<int> p1 = create_Thing(p);
    std::cout << *p << std::endl;
    std::cout << *p1 << std::endl;

    return  0;
}
