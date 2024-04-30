#include "Ksiazka.h"

Ksiazka::Ksiazka(std::string title, std::string author, int id, std::string genre, int shelf): title(title), author(author), id(id), genre(genre), shelf(shelf){}

void Ksiazka::wyswietlInformacje() const
{
    std::cout << "Tytuł: " << title <<
    "\nAutor: " << author << std::endl <<
    "Id ksiazki: " << id << "\nGatunek: " << genre <<
    "\nNa półce: " << shelf << std::endl; 
}

int Ksiazka::getId() const
{
    return id;
}

std::string Ksiazka::getTytul() const
{
    return title;
}