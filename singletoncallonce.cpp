#include <iostream>
#include <thread>
class Singleton
{
public:
    Singleton() {}
    static std::shared_ptr<Singleton> getInstance()
    {
        std::call_once( Singleton::m_flag,
                       []() {
                             std::cout << "Called Once\n";
                             m_instance.reset(new Singleton); }
                        );
        std::cout << "Called each time\n";
        return m_instance;
    }
private:
    static std::once_flag m_flag;
    static std::shared_ptr<Singleton> m_instance;
};

std::once_flag Singleton::m_flag;
std::shared_ptr <Singleton> Singleton::m_instance = nullptr;




int lde(){
    std::thread t1(&Singleton::getInstance);
    std::thread t2(&Singleton::getInstance);
    std::thread t3(&Singleton::getInstance);
    std::thread t4(&Singleton::getInstance);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
