#ifndef CZASOPISMO_H
#define CZASOPISMO_H

#include "IKsiazka.h"

class Czasopismo: private IKsiazka
{
    
    private:

    std::string title, author, genre;
    int id, shelf;
    Czasopismo(std::string title, std::string author, int id, std::string genre, int shelf);

    public:

    static IKsiazka* create(std::string title, std::string author, int id, std::string genre, int shelf){
        return new Czasopismo(title, author, id, genre, shelf);
    }

    void wyswietlInformacje() const override;

    int getId() const override;

    std::string getTytul() const override;

};


#endif