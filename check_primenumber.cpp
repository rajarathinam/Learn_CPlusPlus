#include "stub.h"


#define NO_OF_PRIMES 26

bool checkPrime(int x);
void generatePrimeNumbers(vector<int> &v, int t_end)
{

    for (int i = 2; i <= t_end ; i++)
    {
          if( checkPrime(i))
          {
              v.push_back(i);
          }

    }

}

bool checkPrime(int x)
{

    int count = 0;
    for(int i = 2; i < (x/2) + 1 ; i++)
    {
        if( x%i == 0)
            count++;
    }
    if( 0 == count)
    {
        return true;
    }
    return false;
}

int bnjijoj()
{

    vector<int> primes;

    generatePrimeNumbers(primes,200);
    int size = primes.size();
    for(int i =0 ; i < size ; i++)
    {
        cout << " " << primes[i];
    }
    return 0;
}
