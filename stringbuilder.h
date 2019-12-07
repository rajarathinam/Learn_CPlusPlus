/*
 * stringbuilder.h
 *
 *  Created on: 09-Feb-2012
 *      Author: rathinam
 */

#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_

#include <iostream>
using namespace std;
class Empty
{
public:
	Empty()
	{
		cout<<"Empty::Empty()"<<endl;
	}
	~Empty()
	{
		cout<<"Empty::Desstructor"<<endl;
	}
};
class Empty1
{
public:
	Empty1()
	{
		cout<<"Empty1::Empty1()"<<endl;
	}
	~Empty1()
	{
		cout<<"Empty1::Desstructor"<<endl;
	}
};

class StringBuilder
{
private:
	static int counter;
	char *str;
public:
	StringBuilder();
	StringBuilder(const char *);
	~StringBuilder();
	const char *getString();
	Empty1 x;
	Empty e;

};

#endif /* STRINGBUILDER_H_ */
