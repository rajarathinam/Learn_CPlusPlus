#include "stub.h"
class ReferenceCounter
{
public:
    void increment(){
        ++m_count;
    }
    void decrement(){
        --m_count;
    }
    int getCount(){
        return m_count;
    }
private:
    int m_count;
};

template<class T>
class SmartPtr
{
public:
    SmartPtr(T* p_object):m_object(p_object), m_refcounter(new ReferenceCounter){
        m_refcounter->increment();
        std::cout << "Ref. Count: " << m_refcounter->getCount() << '\n';
    }
    ~SmartPtr()
    {
        if(m_refcounter) {
            m_refcounter->decrement();
            int  count = m_refcounter->getCount();
            if( count <= 0) {
                delete m_object;
                delete m_refcounter;
                m_object = nullptr;
                m_refcounter = nullptr;
            }
        }

    }

private:
    T* m_object{nullptr};
    ReferenceCounter* m_refcounter{nullptr};

};

using namespace std;
void Count(int result)

{

  for (int i = 1; i <= 3; i++)

  {

    result += i;

  }

}
class User
{
    std::string m_id;
    std::string m_name;
public:
    User(std::string name, std::string id) :
            m_id(id), m_name(name)
    {
    }
    const std::string& getId() const
    {
        return m_id;
    }
    const std::string& getName() const
    {
        return m_name;
    }
    bool operator<(const User& userObj) const
    {
        if (userObj.m_id < this->m_id)
            return true;
    }
};

void example_1()
{
    std::set<User> m_UserInfoMap;

    m_UserInfoMap.insert(User("Mr.X", "3"));
    m_UserInfoMap.insert(User("Mr.X", "1"));
    m_UserInfoMap.insert(User("Mr.Z", "2"));


}
struct UserNameComparator
{
    bool operator()(const User &left, const User &right) const
    {
        return (left.getName() > right.getName());
    }
};

void example_2()
{
    std::map<User, int> m_UserInfoMap;

    m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "3"), 100));
    m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "1"), 120));
    m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.Z", "2"), 300));

    std::map<User, int, UserNameComparator>::iterator it =
            m_UserInfoMap.begin();
    for (; it != m_UserInfoMap.end(); it++)
    {
        std::cout << it->first.getName() << " :: " << it->second << std::endl;
    }
}
int dndn()
{
    std::cout << "EXAMPLE 1 :: Comparing by ID" << std::endl;
    example_1();
    std::cout << "EXAMPLE 1 :: Comparing by NAME" << std::endl;
    example_2();
    return 0;
}
