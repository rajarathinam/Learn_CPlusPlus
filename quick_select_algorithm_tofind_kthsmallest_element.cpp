
#include "stub.h"
// A simple print function
void print(int *input)
{
    for ( int i = 0; i < 5; i++ )
        cout << input[i] << " ";
    cout << endl;
}

int xpartition(int* input, int p, int r)
{
    int pivot = input[(p+r)/2];
    
    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;
        
        while ( input[r] > pivot )
            r--;
        
        if ( input[p] == input[r] )
            p++;
        else if ( p < r ) {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    
    return r;
}

int quick_select(int* input, int p, int r, int k)
{
    if ( p == r ) return input[p];
    int j = xpartition(input, p, r);
    int length = j - p + 1;
    if ( length == k ) return input[j];
    else if ( k < length ) return quick_select(input, p, j - 1, k);
    else  return quick_select(input, j + 1, r, k - length);
}

int dwkpfe()
{
    int A1[] = { 7,9,3,2,1 };
    cout << "1st order element " << quick_select(A1, 0, 4, 4) << endl;
	return 0;

}
