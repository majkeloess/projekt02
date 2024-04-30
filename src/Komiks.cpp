#include "Komiks.h"

Komiks::Komiks(std::string title, std::string author, int id, std::string genre, int shelf): title(title), author(author), id(id), genre(genre), shelf(shelf){}

void Komiks::wyswietlInformacje() const
{
    std::cout << "Tytuł: " << title <<
    "\nAutor: " << author << std::endl <<
    "Id ksiazki: " << id << "\nGatunek: " << genre <<
    "\nNa półce: " << shelf << std::endl; 
}

int Komiks::getId() const
{
    return id;
}

std::string Komiks::getTytul() const
{
    return title;
}