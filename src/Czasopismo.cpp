#include "Czasopismo.h"

Czasopismo::Czasopismo(std::string title, std::string author, int id, std::string genre, int shelf): title(title), author(author), id(id), genre(genre), shelf(shelf){}


void Czasopismo::wyswietlInformacje() const
{
    std::cout << "Tytuł: " << title <<
    "\nAutor: " << author << std::endl <<
    "Id ksiazki: " << id << "\nGatunek: " << genre <<
    "\nNa półce: " << shelf << std::endl; 
}

int Czasopismo::getId() const
{
    return id;
}

std::string Czasopismo::getTytul() const
{
    return title;
}