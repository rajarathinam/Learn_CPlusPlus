#include "stub.h"
void distinctPairsDifferenceToK(int arr[], int size, int diff)
{
    std::unordered_set<int> myset;
    int count  = 0;
    for (auto i = 0; i < size; ++i) {
     if( myset.find(arr[i] + diff) != myset.end() )
     {  ++count;
         std::cout << arr[i] <<  " , " << arr[i] + diff << std::endl; }

     if( myset.find(arr[i] - diff) != myset.end() )
     {
         ++count;
         std::cout << arr[i] <<  " , " << arr[i] - diff << std::endl; }

     myset.insert(arr[i]);
    }

    std::cout << count << std::endl;
}

void pairsSumToK(int arr[], int size, int sum)
{
    std::unordered_set<int> myset;
    int count  = 0;
    for (auto i = 0; i < size; ++i) {
     if( myset.find(sum - arr[i]) != myset.end() )
     {   ++count;
         std::cout << arr[i] <<  " , " << sum - arr[i] << std::endl;
     }
     myset.insert(arr[i]);
    }

    std::cout << count << std::endl;
}

int sisj()
{

    return 0;
 }
