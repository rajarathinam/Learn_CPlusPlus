
#include<memory>
#include<iostream>
using namespace std;
struct A;
struct B;

struct A {
   shared_ptr<B> bptr;
   ~A() {cout << "A is deleted!" << endl;}
};

struct B {
   shared_ptr<A> aptr;
   ~B() {cout << "B is deleted!"<< endl;}
};
void useAnB() {
  auto aptr = std::make_shared<A>();
  auto bptr = std::make_shared<B>();
  aptr->bptr = bptr;
  bptr->aptr = aptr;
}

int maiwwwn() {
   useAnB();
   std::cout << "Finished using A and B\n";
}
