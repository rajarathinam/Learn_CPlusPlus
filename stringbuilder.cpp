#include <cstring>
#include <iostream>

#include "stringbuilder.h"

int StringBuilder::counter = 0;

StringBuilder::StringBuilder()
{
	const char *defaultStr = "Default String";
	int len = std::strlen(defaultStr);
	str = new char[len + 1];
	std::strcpy(str,"Default String");
	counter++;
	std::cout <<"Default Constructor counter=" << counter << std::endl;
}

StringBuilder::StringBuilder(const char *s)
{
	int len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	counter++;
	std::cout <<"Constructor counter=" << counter << std::endl;
}

StringBuilder::~StringBuilder()
{
	counter--;
	std::cout <<"Destructor counter=" << counter << std::endl;
	delete str;
}

const char* StringBuilder::getString()
{
	return str;
}
int hsicekv()
{
	StringBuilder myStringA;  //default constructor
	//StringBuilder myStringB("StringB");  //constructor taking const char *
	//StringBuilder *myStringC = new StringBuilder("StringC");
	//StringBuilder myStringD = myStringC;  //copy constructor

	//std::cout << "myStringA.str = " << myStringA.getString() << std::endl;
	//std::cout << "myStringB.str = " << myStringB.getString() << std::endl;
	//std::cout << "myStringC->str = " << myStringC->getString() << std::endl;
	//std::cout << "myStringD.str = " << myStringD.getString() << std::endl;

	//delete myStringC;
	return 0;
}

