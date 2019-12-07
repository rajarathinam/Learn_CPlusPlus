#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <stdio.h>
template <size_t T, class DataType>
size_t findSize(DataType (&ar)[T])
{
    return (sizeof(DataType) * T);
}

void fn(int a[])
{
    //std::cout << findSize();
}

int fyguho()
{
    int x = printf("Hello World");
    std::cout << x;
    std::cout << '\n';
    return 0;
}
/*
 * #include <iostream>
#include <thread>
#include <future>

int accumulate1()
{
    int sum = 0;
    for (int i = 0;i < 5;++i) {
        sum += i;

    }
   // p.set_value(sum);
    return sum;
}

int main()
{

    //std::promise<int> accumulatePromise;
    //std::future<int> accumulateFuture = accumulatePromise.get_future();
    //std::thread t(accumulate1, std::move(accumulatePromise));


    auto accumulateFuture = std::async([]() { return accumulate1();});

    std::cout << " SUM = " << accumulateFuture.get();
    std::cout << '\n';
    return 0;
}
*/
