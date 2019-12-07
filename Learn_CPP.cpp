
#include <iostream>

#include <string.h>

using namespace std;



void xswap(char* first, char* second)
{

       char ch = *second;

        *second = *first;

        *first = ch;

}



int permute(char* set, int begin, int end)

{
       int i;
        int range = end - begin;
        if (range == 1) {

                cout << set << endl;

        } else {
                for(i=0; i<range; i++) {

                        xswap(&set[begin], &set[begin+i]);                //initial swap

                        permute(set, begin+1, end);                                //recursion

                        xswap(&set[begin], &set[begin+i]);       //swap back

                }

        }

        return 0;

}



//Example Implementation -- Up to you on how to use

int zx001()

{

        char str[255]; //string

        cout << "Please enter a string: ";

        cin.getline(str, 255); //take string
        int len=strlen(str);

        permute(str, 0, len); //permutate the string

        return 0;

}
