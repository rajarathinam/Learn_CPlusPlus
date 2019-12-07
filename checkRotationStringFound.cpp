#include<iostream>
#include<string.h>
using namespace std;
#include <stdio.h>
bool checkRotation(string s1,string s2)
{
	if(s1.length() != s2.length())
		return false;
	else
	{
		s1+=s1;
		if(s1.find(s2) != string::npos)
			return true;
		else
			return false;

	}
}
int hhi()
    {
		string name1="Raja";
		string name2="aRas";
	cout<<checkRotation(name1,name2);
            return 0;
    }
