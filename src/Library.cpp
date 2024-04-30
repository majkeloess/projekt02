#include "Library.h"

Library::~Library()
{
    for (auto* book : Books) {
        delete book;
    }
}

void Library::addMaterial(IKsiazka* material) 
{
    Books.push_back(material);
}

void Library::borrowBook(const std::string& title, User& user)
{
    IKsiazka* book = findBookByTitle(title);
    if (book && borrowedBooks.find(book->getId()) == borrowedBooks.end()) {
        borrowedBooks[book->getId()] = user.getName();
        user.borrowBook(book);
        std::cout << "Użytkownik " << user.getName() << " wypożyczył książkę: " << title << std::endl;
    } else {
        std::cout << "Przepraszamy, książka \"" << title << "\" jest już wypożyczona lub nie istnieje." << std::endl;
    }
}

void Library::returnBook(const std::string& title, User& user)
{
    IKsiazka* book = findBookByTitle(title);
    if (book && borrowedBooks.find(book->getId()) != borrowedBooks.end() && borrowedBooks[book->getId()] == user.getName()) {
        borrowedBooks.erase(book->getId());
        user.returnBook(book);
        std::cout << "Użytkownik " << user.getName() << " zwrócił książkę: " << title << std::endl;
    } else {
        std::cout << "Przepraszamy, książka \"" << title << "\" nie została wypożyczona przez tego użytkownika lub nie istnieje." << std::endl;
    }
}

void Library::displayAllBooks() const
{
    std::cout << "\nLista książek w bibliotece:\n";
    for (const auto* book : Books) {
        book->wyswietlInformacje();
        std::cout << "Status: " << (borrowedBooks.find(book->getId()) == borrowedBooks.end() ? "Dostępny" : "Wypożyczony") << std::endl << std::endl;
    }
}

IKsiazka* Library::findBookByTitle(const std::string& title) const
{
    for (auto* book : Books) {
        if (book->getTytul() == title) {
            return book;
        }
    }
    return nullptr;
}
