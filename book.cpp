
#include <iostream>
#include "book.h"
class BookImpl
{
public:
    BookImpl()
    {
        m_content = "Raja";
    }
    ~BookImpl() {}
    void print()
    {
        std::cout << m_content;
    }
private:
    std::string m_content;
    std::string m_title;
};


Book::Book() : impl(new BookImpl){}

Book::~Book() {}
void Book::print()
{
    impl->print();
}
