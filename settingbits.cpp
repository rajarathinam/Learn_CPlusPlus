/*
 * settingbits.cpp
 *
 *  Created on: 20-Aug-2010
 *      Author: rathinam
 */

#include<iostream>
#include<stdio.h>
using namespace std;
typedef char BYTE;

class Base1 {

public:

    void Hi1()

    {    printf("Hi from Base1!\n");  }

    BYTE a1[100];

};



class Base2 {

public:

    void Hi2()

    {    printf("Hi from Base2!\n");  }

    BYTE a2[100];

};



class Base3 {

public:

    void Hi3()

    {    printf("Hi from Base3!\n");  }

    BYTE a3[100];

};



class Derived : public Base1, public Base2, public Base3 {

public:

    void Hi()

    {    printf("Hi from Derived!\n");  }

    BYTE a[100];

};



int chiuehi()

{

    Derived * pDerived = new Derived;

    Base1 * pBase1 = (Base1 *)pDerived;

    pBase1->Hi1();

    Base2 * pBase2 = (Base2 *)pDerived;

    pBase2->Hi2();

    Base3 * pBase3 = (Base3 *)pDerived;

    pBase3->Hi3();
    return 0;

}


