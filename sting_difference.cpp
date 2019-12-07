
#include "stub.h"


unsigned int   countCharDifference(const string& str1, const string& str2)
{

	
	unsigned int  length1 = str1.length();
	unsigned int  length2 = str2.length();
	if(  length1 <= 0 && length2 > 0 )
		return length2;
	if(  length2 <= 0 && length1 > 0 )
		return length1;

    if( length2 == 0 && length1 == 0)
		return 0;

	  map<char,int> mymap1;
	  unsigned int i=0;
	  while(i < length1)
	  {
	    mymap1[str1[i++]]++;
	  
	  }
	  i=0;
	  map<char,int>::iterator it;
	  while(i < length2)
	  {
		 
	     mymap1[str2[i++]]--;
		
	  }

	  int diff = 0;
	  
	  for( it= mymap1.begin(); it != mymap1.end();++it)
	  {
		  if(  it->second != 0)
			  diff++;
	  }
	  return diff;
	
}

int qaa()
{
	string str1("Roja");
	string str2("Raja");
	cout << "\n No. of char diff:" << countCharDifference(str1,str2);

	cout << endl;
	return 0;

  





  
}