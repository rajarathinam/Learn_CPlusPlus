#include <memory>
#include <condition_variable>
#include <iostream>
#include <mutex>
class Semaphore
{
public:
    Semaphore()
    {
        m_s = 0;
    }
    Semaphore(int n)
    {
        m_s = n;
    }
    void wait()
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        while(m_s == 0)
        {
            m_condition.wait(locker);
        }
        m_s--;
    }
    void signal()
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_s++;
        m_condition.notify_all();
    }

private:
    std::atomic<int> m_s;
    std::mutex m_mutex;
    std::condition_variable m_condition;
};

template<typename ... Args>
void f2(Args ... rest)
{
    std::cout << sizeof...(Args) << sizeof... (rest) << std::endl;
}
void customDeleter(Semaphore *ptr)
{
    std::cout << "Custom Deleter called\n";
}

int shvdvhik()
{
    int x = 10;
    //std::string str = "Raja";
    f2(x);
    std::cout << "\n";
    return 0;
}
