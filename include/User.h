#ifndef USER_H
#define USER_H

#include <string>
#include <algorithm>
#include "IKsiazka.h"

class User
{
    private:

    std::string name;
    
    std::vector<IKsiazka*> borrowedBooks;

    public:
    User(std::string name);
    
    std::string getName() const;

    void displayBorrowedBooks() const;

    void borrowBook(IKsiazka* book);

    void returnBook(IKsiazka* book);
};

#endif