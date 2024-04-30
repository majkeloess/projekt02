#ifndef LIBRARY_H
#define LIBRARY_H

#include "IKsiazka.h"
#include "User.h"
#include <unordered_map>


class Library
{
    private:

    std::vector<IKsiazka*> Books;
    std::unordered_map<int, std::string> borrowedBooks;

    IKsiazka* findBookByTitle(const std::string& title) const;


    public:

    ~Library();
    void addMaterial(IKsiazka* material);
    void borrowBook(const std::string& title, User& user);
    void returnBook(const std::string& title, User& user);
    void displayAllBooks() const;

};


#endif