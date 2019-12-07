#include<iostream>
using namespace std;


class Sample
{
public:
	Sample()
	{
		x = 0;
	}
	Sample(int xx)
	{
		x = xx;
	}
	~Sample()
	{
	}
private:
	int x;
	void* operator new(size_t xx)
	{
	}
	
};
int dwdw()
{

	//Sample *ptr= new Sample(10);
	//delete ptr;
	return 0;
}

