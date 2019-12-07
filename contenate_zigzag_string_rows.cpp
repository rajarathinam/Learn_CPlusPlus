#include "stub.h"


void concatzigzagstring(string str, int t_rows)

{


    if( str.length() == 1)
     {
         cout << str;
         return;
     }


    string out[t_rows];
    int row = 0;
    bool down = true;
    int string_length = str.length();


    for(int i =0 ; i < string_length;++i)
    {

        out[row].push_back(str[i]);

        if( row == t_rows -1 )
        {
            down = false;
        }
        else if( row ==0)
        {
            down = true;
        }

        if(down)
        {
            row++;

        }
        else
        {
            row--;
        }


    }
    // Print concatenation of all rows
       for (int i = 0; i < t_rows; ++i)
           cout << out[i];

}

int mqaaain()
{

     string str = "ABCDEF";

    concatzigzagstring(str,2);





    cout << endl;
    return 0;
}
