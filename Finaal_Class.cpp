
#include "stub.h"
class Final;  // The class to be made final
 
class MakeFinal // used to make the Final class final
{
private:
    MakeFinal() { cout << "MakFinal constructor" << endl; }
friend class Final;
};
 
class Final : public virtual MakeFinal
{
public:
    Final() { cout << "Final constructor" << endl; }
};
 /*uncomment
class Derived : public Final // Compiler error
{
public:
    Derived() { cout << "Derived constructor" << endl; }
};
 */


int qqq(int argc, char *argv[])
{
   // Derived d;
    return 0;
}