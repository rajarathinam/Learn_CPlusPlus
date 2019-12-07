#include<iostream>
using namespace std;

char mytoupper(char ch)
{
	if((ch >= 'a')&&(ch <='z'))
		return('A'+ ch -'a');
	else
		return ch;

}

int xscink()
{
	cout<<mytoupper('x')<<endl;
	return 0;
}


