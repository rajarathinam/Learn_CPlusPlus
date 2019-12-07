
#include "stub.h"
unsigned int reverseBits(unsigned int n)
{
  unsigned int i, nrev,N;   // nrev will store the bit-reversed pattern
    N = 1<<3;            // find N: shift left 1 by the number of bits
    nrev = n;  

    for(i=1; i<3; i++)
    {
        n >>= 1;
        nrev <<= 1;
        nrev |= n & 1;   // give LSB of n to nrev
    }
    nrev &= N-1;         // clear all bits more significant than N-1
   
    return nrev;
}
int swswd()
{
  cout<<reverseBits(2)<<endl;
  return 0;
}
