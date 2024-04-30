#ifndef KSIAZKA_H
#define KSIAZKA_H

#include "IKsiazka.h"

class Ksiazka: private IKsiazka
{
    private:

    std::string title, author, genre;
    int id, shelf;
    Ksiazka(std::string title, std::string author, int id, std::string genre, int shelf);
    
    public:
    static IKsiazka* create(std::string title, std::string author, int id, std::string genre, int shelf){
        return new Ksiazka(title,author,id,genre,shelf);
    }
    void wyswietlInformacje() const override;
    std::string getTytul() const override;
    int getId() const override;

};

#endif