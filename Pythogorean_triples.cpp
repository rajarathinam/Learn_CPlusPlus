#include <iostream>
#include <cmath>
#include <set>
#include "stub.h"
using namespace std;


int ersfewf()
{
	int array[] = { 2, 3, 4, 6, 7, 12, 13, 15, 5, 17, 14, 22 };
	set<int> squares;
	for(int i=0; i < 12; i++)
	{
		squares.insert(array[i]* array[i]);
	}

	for( int i =0; i < 12; i++)
	{
		for( int j= i+1; j < 12; j++)
		{
			int square = (array[i] * array[i]) + (array[j] * array[j]);
			set<int>::const_iterator got = squares.find(square);
			 if ( got != squares.end() )
			 {   
             //cout<<array[i]<<","<<array[j]<<","<<sqrt(long double(*got))<<endl;
			 }
		}
	}
	return 0;
}
