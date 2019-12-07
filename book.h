#ifndef BOOK_H
#define BOOK_H
#include <string>
class BookImpl;
class Book
{
public:
    Book();

    Book(const Book& rhs) = default;
    Book& operator=(const Book& rhs) = default;

    Book (Book&& rhs) = default;
    Book& operator=(Book&& rhs) = default;

    ~Book();

    void print();

   std::string getTittle() const;

private:

   std::unique_ptr<BookImpl> impl;


};
#endif // BOOK_H
