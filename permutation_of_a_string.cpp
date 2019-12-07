#include "stub.h"
/*
void swap(char *s, char *e)
{
	*s = *s + *e;
	*e = *s - *e;
	*e = *s - *e;
}

void permutate( char *ptr, int index)
{
	unsigned int i=0;
	if( strlen(ptr) ==  index)
	{
		cout<<ptr<<endl;
	    return;
	}
	else
	{
		for( i = index; i < strlen(ptr); i++)
		{
			swap(ptr[index], ptr[i]);
			permutate(ptr,index + 1);
			swap(ptr[index], ptr[i]);
		}
	}

}
*/

void permutate(std::string& str, int i)
{
    int n = str.length();
    if( n == i)
    {
        std::cout << str << std::endl;
        return;
    } else {
        for(int j = i; j < n; ++j)
        {
            std::swap(str[i], str[j]);
            permutate(str, i+1);
            std::swap(str[i], str[j]);
        }
    }

}

int shishis()
{
     std::string str = "ABC";
     permutate(str,0);
	return 0;
}


