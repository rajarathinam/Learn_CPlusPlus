#include<iostream>
#include<string.h>
#include <vector>
using namespace std;

class String
{
private:
    char *ptr;
public:
    String(char *xptr="default")
    {
        std::cout << "constructor called\n";
        ptr=new char[strlen(xptr)];
        strcpy(ptr,xptr);
    }
    String (const String& rhs)
    {
      cout<<"Copy Constructor called " << rhs.ptr <<endl;
    }

    String(String&& rhs)
    {
        this->ptr = rhs.ptr;
        rhs.ptr = nullptr;
        std::cout << "\n Move Constructor called";
    }
    String& operator=(const String& that)
    {
    	cout<<"Assignement Opearator"<<endl;

    	if(this != &that )
    	{
    		delete ptr;
    		try
    		{
    			ptr=new char(strlen(that.ptr) + 1);
    			strcpy(ptr,that.ptr);
        		return (*this);
    		}
    		catch(...)
    		{
    			delete ptr;
    			throw;
    		}
    	}
    	else
    	{
    		return (*this);
    	}

    }
    String operator+ (const String& obj2)
    {

        char *str=new char[strlen(ptr)+strlen(obj2.ptr)+1];
        strcpy(str,ptr);
        strcat(str,obj2.ptr);
        return String(str);
    }
    String operator+=(const String& obj2)
    {
        char *temp=ptr;
        ptr=new char[strlen(ptr)+strlen(obj2.ptr)+1];
        strcpy(ptr,temp);
        strcat(ptr,obj2.ptr);
        return String(ptr);
    }
    bool find(char *str)
    {
        int u8MainStrCount    = 0;
        bool ePresent      = false;
        int u8TempCount       = 0;
        int u8SubStrCount     = 0;
        int u8MainStrLen=strlen(ptr);
        int u8SubStrLen=strlen(str);

        for (u8MainStrCount = 0; u8MainStrCount < u8MainStrLen;
                u8MainStrCount++)
        {
            u8TempCount = u8MainStrCount;
            u8SubStrCount = 0;
            while (u8SubStrCount < u8SubStrLen)
            {
                // If a charcater of the main string matches with the character
                // of substring increment the count of both strings and continue
                // the search
                if (ptr[u8TempCount] == str[u8SubStrCount])
                {
                    u8SubStrCount++;
                    u8TempCount++;

                    // If the search completes, then the string is found
                    // else this loop is exited prematurely with substring not
                    // found

                    if (u8SubStrCount == u8SubStrLen)
                    {
                        ePresent = true;
                        u8MainStrCount = u8MainStrLen;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return ePresent;
    }
    String substring(int start, int end)
    {
    	char  *str=new char [end-start+2];
    	int j=0;
    	for(int i=start-1;i<end;i++)
    	{
    		str[j]=ptr[i];
    		j++;
    	}
    	str[j]='\0';
    	return String(str);
    }
    size_t length()
    {
    	return strlen(this->ptr);
    }
    size_t size()
    {
    	return strlen(this->ptr);
    }
    char  operator[] (int index)
    {
    	return ptr[index];
    }
    void display()
    {
        cout<<"\n"<<ptr;

    }
	/*
	ostream& operator <<(ostream& out, const String& obj)
	{
		out<<obj.ptr;
	}
	*/
    ~String()
    {
        delete[] ptr;
    }
};

String f1()
{
   return String("Hello");
}

template<class T>
T mysquare(T x)
{
   retur  (x *x);
}
#define Square(x) ({    \
    decltype(x) y = (x);  \
    y*y;                \
})

int mwwwwwain()
{
    int a = 10;
     std::cout << Square(++a);
   std::cout << '\n';
   return 0;
}

