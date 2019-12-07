#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
int kthlargestElement(std::vector<int>& vec, int k)
{
//Max Heap - Largest Element on top
   std::make_heap(vec.begin(), vec.end(), std::less<int>());
   return vec[k-1];


    //Min Heap - Lowest Element on Top
    std::make_heap(v.begin(), v.end(), std::greater<int>());

}
*/
void bubble_sort1(int a[], int length, int kthLargest)
{
    int n = length ;
    for(int i = 0; i < kthLargest ; i++)
    {
        for(int j = 0; j < (n - i - 1) ; j++)
        {
            if(  a[j] > a[j + 1])
                std::swap(a[j],a[j+1]);
        }
    }
}

int shiehjeo()
{

    //Also refer the selection sort code
    int array[] = {9,1,8,2,7};

    bubble_sort1(array,5, 2);
    std::cout << '\n';
    return 0;
}
