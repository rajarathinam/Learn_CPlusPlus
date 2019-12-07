#include <iostream>

#include "book.h"

int sjskk()
{
    std::shared_ptr<Book> book = std::make_shared<Book>();
    book->print();
    std::cout << '\n';
    return 0;
}
