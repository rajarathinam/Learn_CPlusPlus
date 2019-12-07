
/*
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable notfull;
std::condition_variable notempty;
int usedBufferSize = 0;

#define BUFFER_SIZE 100

#define DATA_SIZE 1000

int buffer[BUFFER_SIZE];


void producer()
{
    for(int i = 0; i < DATA_SIZE; i = i + 10)
    {
        std::unique_lock<std::mutex> locker(mu);
        notfull.wait(locker,[](){ return (usedBufferSize != BUFFER_SIZE); });
        buffer [i % BUFFER_SIZE ] = i;
        for(int j = 1; j <= 5; ++j )
        {
          std::cout << "T1 :    " << (i +j) << std::endl;
        }

        usedBufferSize++;
        locker.unlock();

        notempty.notify_one();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

}

void consumer()
{
    for(int i = 0; i < DATA_SIZE; i = i + 10)
    {
        std::unique_lock<std::mutex> locker(mu);
        notempty.wait(locker,[](){ return (usedBufferSize != 0); });
        for(int j = 6; j <= 10; ++j )
        {
          std::cout << "T2 :    " << (i +j) << std::endl;
        }


       // std::cout << "consume data :    " << buffer [i % BUFFER_SIZE ] << std::endl;
        usedBufferSize--;
        locker.unlock();

        notfull.notify_one();
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable cond;
int count = 1;
bool oddReady = true;

void PrintOdd()
{
    for(; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait_for(locker,std::chrono::seconds(12),[](){ return (oddReady == true); });
        std::cout << "From Odd:    " << count << std::endl;
        count++;
        oddReady = false;
        locker.unlock();

        cond.notify_all();
    }

}

void PrintEven()
{
    for(; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait_for(locker,std::chrono::seconds(12),[](){ return (oddReady == false); });
        std::cout << "From Even: " << count << std::endl;
        count++;
        oddReady = true;
        locker.unlock();

        cond.notify_all();
    }
}




int aadaw()
{

   // std::thread t1(PrintOdd);
   // std::thread t2(PrintEven);
  //  t1.join();
   // t2.join();
    return 0;
}


/*
#include <iostream>
#include <thread>

std::mutex m;
std::condition_variable oddCondition;
std::condition_variable evenCondition;
bool oddFlag  = true;
void OddFunction()
{
    for(int i = 1; i < 100; i += 2)
    {
    std::unique_lock<std::mutex> lock(m);
    if(oddFlag == false)
    {
        evenCondition.wait(lock);
    }
    lock.unlock();

    std::cout << "\nOdd: " << i;

    std::unique_lock<std::mutex> lock1(m);
    oddFlag = false;
    oddCondition.notify_all();
    lock1.unlock();

    }

}

void EvenFunction()
{
    for(int i = 2; i < 100; i += 2)
    {
    std::unique_lock<std::mutex> lock(m);
    if(oddFlag == true)
    {
        oddCondition.wait(lock);
    }
    lock.unlock();

    std::cout << "\nEven: " << i;

    std::unique_lock<std::mutex> lock1(m);
    oddFlag = true;
    evenCondition.notify_all();
    lock1.unlock();

    }


}


int main()
{
    std::thread t1(&OddFunction);
    std::thread t2(&EvenFunction);

    std::cout << "main thread ";
    t1.join();
    t2.join();
    return 0;
}

*/
