#include "stub.h"
/*
int findLCS(const std::string& A, const std::string& B)
{
       int m = A.length();
       int n = B.length();
       if( ( m == 0) || ( n == 0))
       {
           return 0;
       }
       if( A[m-1] == B[n-1])
       {
           return  ( 1 + findLCS(A.substr(0, m-1) , B.substr(0, n - 1)) );
       } else {
           return  std::max( findLCS(A.substr(0, m - 1), B.substr(0, n)),
                             findLCS(A.substr(0, m), B.substr(0, n - 1)));
       }
}
*/


int findLCS(const std::string& A, const std::string& B)
{
    int m = A.length();
    int n = B.length();
    if( ( m == 0) || ( n == 0))
    {
        return 0;
    }
    int LCS[m+1][n+1];
    std::memset(LCS, 0, sizeof (LCS));

    for (auto i = 1; i <= m; ++i) {
        for(auto j  = 1; j <= n; ++j)
        {
            if( A[i-1] == B[j-1])
            {
                LCS[i][j] =  1 + LCS[i-1][j-1];
            } else {
                LCS[i][j] = std::max(LCS[i -1][j], LCS[i][j-1]);
            }
        }
    }
    int result = LCS[m][n];
    return result;

}


int skas()
{
    std::string A = "ACBDEA";
    std::string B = "ABCDA";
    int length = findLCS(A, B);
    std::cout << length  << std::endl;
}
