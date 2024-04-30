#include "User.h"

User::User(std::string name): name(name){}

std::string User::getName() const
{
    return name;
}

void User::displayBorrowedBooks() const{
    if (borrowedBooks.empty()) {
        std::cout << "Brak wypożyczonych książek przez użytkownika." << std::endl;
        return;
    }
    std::cout << "Lista wypożyczonych książek przez użytkownika:" << std::endl;
    for (const auto* book : borrowedBooks) {
        std::cout << "Tytuł: " << book->getTytul() << std::endl;
    }
}

void User::borrowBook(IKsiazka* book)
{
    for (auto* borrowed : borrowedBooks) {
        if (borrowed == book) {
            std::cout << "Książka już wypożyczona przez tego użytkownika." << std::endl;
            return;
        }
    }

    borrowedBooks.push_back(book);
}

void User::returnBook(IKsiazka* book) {

    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    } else {
        std::cout << "Ta książka nie została wypożyczona przez tego użytkownika." << std::endl;
    }
}

