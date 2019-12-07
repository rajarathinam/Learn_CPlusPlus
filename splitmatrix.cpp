
// C++ program to compute submatrix query sum in O(1)
// time
#include<iostream>
using namespace std;
#define M 2
#define N 3

// Function to preprcess input mat[M][N]. This function
// mainly fills aux[M][N] such that aux[i][j] stores sum
// of elements from (0,0) to (i,j)
int preProcess(int mat[M][N], int aux[M][N])
{
// Copy first row of mat[][] to aux[][]
for (int i=0; i<N; i++)
    aux[0][i] = mat[0][i];

// Do column wise sum
for (int i=1; i<M; i++)
    for (int j=0; j<N; j++)
        aux[i][j] = mat[i][j] + aux[i-1][j];

// Do row wise sum
for (int i=0; i<M; i++)
    for (int j=1; j<N; j++)
        aux[i][j] += aux[i][j-1];
}

// A O(1) time function to compute sum of submatrix
// between (tli, tlj) and (rbi, rbj) using aux[][]
// which is built by the preprocess function
int sumQuery(int aux[M][N], int tli, int tlj, int rbi,
                                            int rbj)
{
    // result is now sum of elements between (0, 0) and
    // (rbi, rbj)
    int res = aux[rbi][rbj];

    // Remove elements between (0, 0) and (tli-1, rbj)
    if (tli > 0)
    res = res - aux[tli-1][rbj];

    // Remove elements between (0, 0) and (rbi, tlj-1)
    if (tlj > 0)
    res = res - aux[rbi][tlj-1];

    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if (tli > 0 && tlj > 0)
    res = res + aux[tli-1][tlj-1];

    return res;
}

// Driver program
int suiui()
{
int mat[M][N] = {{1, 2, 3},
                  {4, 5, 6}
                };
int aux[M][N];

preProcess(mat, aux);

int tli = 2, tlj = 2, rbi = 3, rbj = 4;
cout << "\nQuery1: " << sumQuery(aux, tli, tlj, rbi, rbj);

tli = 0, tlj = 0, rbi = 1, rbj = 1;
cout << "\nQuery2: " << sumQuery(aux, tli, tlj, rbi, rbj);

tli = 1, tlj = 2, rbi = 3, rbj = 3;
cout << "\nQuery3: " << sumQuery(aux, tli, tlj, rbi, rbj);

return 0;
}

/*
  #include <iostream>


#define COLUMN  4
#define ROW  4

#define SUBCOLUMN 2
#define SUBROW 2

int** splitMatrix(int a[][COLUMN], int offsetx, int offsety, int rowSize, int colSize)
{
    int **ptr = new int*[rowSize];

    for(int x = offsetx, row = 0; x < offsetx + rowSize; ++x, ++row)
    {
        ptr[row] = new int[colSize];
        for (int y = offsety, col = 0; y < offsety + colSize; ++y, ++ col)
        {

            ptr[row][col] = a[x][y];
        }

    }
    return ptr;

}

int calculateSum(int **a, int rowCount, int colCount)
{
    int sum = 0;
    for(int i = 0; i < rowCount; ++i)
    {
        for(int j = 0; j < colCount; ++j)
        {
            sum += a[i][j];
        }
    }
    return sum;
}

void displayMatrix(int **a,int rowCount, int colCount)
{
    for(int i = 0; i < rowCount; ++i)
    {
        for(int j = 0; j < colCount; ++j)
        {
            std::cout << " " << a[i][j];
        }
        std::cout << '\n';
    }
}
int main()
{
    int a[][4] = { {1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}
                 };



    for(int x = 0; x < 4; x += SUBROW)
    {
        for(int y = 0;  y < 4; y += SUBCOLUMN)
        {

         int **subMatrix = splitMatrix(a, x, y, SUBROW, SUBCOLUMN);
         displayMatrix(subMatrix, SUBROW, SUBCOLUMN);
         int sum = calculateSum(subMatrix, SUBROW, SUBCOLUMN);

         std::cout << "SUM = " << sum << '\n' << "=======================\n";
          }



    }




    std::cout << '\n';
    return 0;
}
*/
