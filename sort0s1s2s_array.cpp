// C program to sort an array with 0,1 and 2
// in a single pass
#include<stdio.h>

/* Function to swap *a and *b */
void swap(int *a, int *b);

// Sort the input array, the array is assumed to
// have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    while (mid <= hi)
    {
        switch (a[mid])
        {
        case 0:
            swap(&a[lo++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}

/* UTILITY FUNCTIONS */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Utility function to print array arr[] */
void printArray1(int arr[], int arr_size)
{
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* driver program to test */
int w33w()
{
    int arr[3] = {2,1,0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;

    sort012(arr, arr_size);

    printf("array after segregation ");
    printArray1(arr, arr_size);

    getchar();
    return 0;
}

