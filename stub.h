#ifndef STUB_H
#define STUB_H
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<bitset>
#include<cstdlib>
#include <iomanip>
#include <sstream>
#include<cstdio>
#include <limits>
#include <unordered_map>
#include <fstream>
#include <functional>
#include <unordered_set>
#include <string>
#include <thread>
#include <future>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }


};

template <class T>
        void f(T& x);
#endif // STUB_H

