#include<iostream>
using namespace std;

class A
{
public:
	int z;
	virtual void f1()
	 {
		 cout<<"A::f1()"<<endl;
	 }
	  virtual void f2()
		 {
			 cout<<"A::f2()"<<endl;
		 }
	  virtual void f3()
		 {
			 cout<<"A::f2()"<<endl;
		 }

};
class B:public A
{
public:


	virtual void f1()
	{
		cout<<"B:f1()"<<"\t"<<endl;
	}



};

 class C:public B
  {
 	 public:
	 	 void f1()
	 	{
	 		cout<<"C:display()"<<"\t"<<endl;
	 	}

  };

int sfwgf()
{
   A a;
   B b;
   C c;
   A *aptr;
   B *bptr;
   C *cptr;
   aptr=&c;
  aptr->f1();

	return 0;
}

