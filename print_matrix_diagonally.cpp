#include <iostream>
#include <vector>
#include <map>
class Raja
{
public:
    Raja(){}
    ~Raja() {};
};

int foo()
{
    return 10;
}

int anji()
{
    Raja obj1;
    Raja obj2 = obj1;
    int y;
    int&& x = foo();

    int a[3][3] = { {1,2,3},
                    {4,5,6},
                    {7,8,9}
                  };
    int rowCount = 3;
    int colCount = 3;

    for (int r = rowCount - 1; r >= 0 ; --r)
    {

        for(int row = r, col = 0; (row < rowCount) && (col < colCount) ; row++, col++)
        {


            std::cout << a[row][col] << " ";
        }

        std::cout << '\n';
    }


    for (int c = 1; c < colCount ; ++c)
    {

        for(int row = 0, col = c; (row < rowCount) && (col < colCount) ; row++, col++)
        {


            std::cout << a[row][col] << " ";
        }

        std::cout << '\n';
    }

    // http://javabypatel.blogspot.com/2016/12/print-matrix-diagonally-or-diagonal.html
/*
    std::multimap<int, std::vector<int> > sumMap;
    for (int r = 0; r < rowCount; ++r)
    {
        int sum = 0;
        std::vector<int> vec;
        for(int row = r, col = 0;(row >= 0) && (col < colCount); row--, col++)
        {
             sum = sum + a[row][col];
             vec.push_back(a[row][col]);
            std::cout << a[row][col] << " ";
        }
        sumMap.insert(std::make_pair(sum, vec));
        std::cout << '\n';
    }

    for (int c = 1; c < colCount; ++c)
    {
        int sum = 0;
        std::vector<int> vec;
        for(int row =  3 - 1, col = c;(row >= 0) && (col < colCount); row--, col++)
        {
            sum = sum + a[row][col];
            vec.push_back(a[row][col]);
            std::cout << a[row][col] << " ";
        }
        sumMap.insert(std::make_pair(sum, vec));
        std::cout << '\n';
    }
    for (auto it = sumMap.begin();it != sumMap.end(); ++it) {
        std::cout << it->first <<  " = ";
        std::vector<int> temp = it->second;
        for (auto it1 = temp.begin(); it1 !=  temp.end();++ it1) {
            std::cout << (*it1) << " ";
        }
        std::cout << '\n';
    }
    */

    return 0;
}
