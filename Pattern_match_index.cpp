#include<iostream>
using namespace std;

#include <iostream>
#include <cmath>
#include <set>
#include<algorithm>
#include <cstring>

using namespace std;

void search(const char *pat, const char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N ; i++)
    {
        int j;
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
        {
            if (txt[i+j] != pat[j])
                break;
        }
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        {
           printf("Pattern found at index %d \n", i+1);
        }
    }
}
  
/* Driver program to test above function */
int jhij()
{
   

    const char *txt = "princeforprincess";
   const char *pat = "prince";
   search(pat, txt);
   getchar();
   return 0;
}

