#include "stub.h"
#include<map>

#define ARRAY_SIZE 10

class ModeAndFrequency
{
private:
	int arr[ARRAY_SIZE];
	int size;
public:
	void get_numbers()
	{
		cout<<"Enter the size of the Array:"<<endl;
		cin>>size;
		cout<<"Enter the Numbers:";
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
	}
	void print_frequency()
	{
		int temp[ARRAY_SIZE] = {0};
		for(int i=0;i<size;i++)
			temp[arr[i]]++;
		for(int i=0;i<size;i++)
		{
			if(temp[i] != 0)
			cout<<i<< "occurs"<<temp[i]<<"times"<<endl;
		}
		map<int,int> array_map;
	
		for(int i=0;i<size;i++)
		{
			if(temp[i] != 0)
			array_map.insert(pair<int,int>(i,temp[i]));
		}
	}
};

int fdtfduh()
{
	//ModeAndFrequency obj_ModeAndFrequency;
	//obj_ModeAndFrequency.get_numbers();
	//obj_ModeAndFrequency.print_frequency();
	  unsigned int from = 0xabcd;
    unsigned int to = ((from & 0xff) << 8) | (from >> 8);
    printf ("%04x\n", to);
    return 0;
	return 0;


	}
		
