//#include "stub.h"
#include <iomanip>
#include<iostream> 
using namespace std;

// for cin, cout
// for setw
// for abs
class nQueens
{
public:
nQueens(int n)
{
   this->n = n;
   col = new int[n]; // array with coordinates of queens
}
~nQueens()
		{
delete col;
		}


void start();
void finish();
void queens(int i);
bool promising(int i);
void OutputSolution();
private:
 int n;
int *col;
// Dimension of board
// col[0..n-1]: col[i]=j means queen at row i, column j
// Statistics: count number of solutions and (non)promising nodes examined.
int numSolutions, numNonPromising, numPromising;
};
void nQueens::start()
{
numSolutions = 0;
numNonPromising = 0;
numPromising = 0;

queens(0);
}
// initialize statistics
void nQueens::finish()
{
// Display statistics
cout<< "# solutions = " << numSolutions;
cout<< "# promising nodes = " << numPromising;
cout<< "# non-promising nodes = " << numNonPromising << endl;
}


void nQueens::queens(int i) {
// Continue only if columns 0,...,i-1 are promising.
if (promising(i-1)) {
numPromising++;
if (i==n) {
// Have a complete solution.
numSolutions++;
OutputSolution();
} else {
for (int j=0; j<n; j++) { // place queen in
col[i] = j;
// row i, column j
queens(i+1);
// and continue to next row
}
}
} else numNonPromising++;
}

// Check if a node is promising
bool nQueens::promising(int i) {
// Check if queen in row k threatens queen in row i
for (int k=0; k<i; k++)
if (col[i] == col[k] || abs(col[i]-col[k]) == i-k)
return false;
// does threaten, so not promising

return true;
// no threats, so promising
}
// Display each solution as it’s found, and statistics
void nQueens::OutputSolution() {
cout << setw(3) << numSolutions
<< " " << setw(3) << numPromising
<< " " << setw(3) << numNonPromising << " ";
for (int i=0; i<n; i++)
cout << "(" << i+1 << "," << col[i]+1 << ") ";
cout << endl;
}
int bjbklk(int argc, char *argv[]) {
int n;
cout << "n-Queens" <<endl;
do {
cout << "Enter n or0 to quit:";
cin >> n;
if (n>0) {
nQueens *nq =new nQueens(n);
nq->start();
nq->finish();
delete nq;
}
} while (n>0);

return 0;
}
