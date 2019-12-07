#include "stub.h"
void  fun(int a[])
{
	a[0] = 999;
}

template <typename T, size_t N>
char (&ArraySizeHelper( T (&array)[N] ))[N];
 
#define countof( array ) (sizeof( ArraySizeHelper( array ) ))

int qwjqi(int argc, char *argv[])
{
	
	

	int array[] = { 1,2,3};
	int size = sizeof(array) / sizeof(*array);
	fun(array);
	cout << array[0];
	cout <<endl;
	
    return 0;
}