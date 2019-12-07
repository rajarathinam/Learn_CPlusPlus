#include<iostream>
#pragma pack(push,1)
using namespace std;
struct Image
{

	char x;
	char v;
	int height;
	float width;
	double y;
};
int hcxhvir()
{
	Image img;
	cout<<"\nint:"<<sizeof(int)<<"\nfloat:"<<sizeof(float)<<"\nchar*:"<<sizeof(char*)<<"\ndouble:"<<sizeof(double);
	cout<<"\nSize of Image:"<<sizeof(img)<<endl;
	return 0;
}
