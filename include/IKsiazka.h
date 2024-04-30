#ifndef IKSIAZKA_H
#define IKSIAZKA_H

#include <string>
#include <iostream>
#include <vector>

class IKsiazka
{
    public: 
    virtual ~IKsiazka(){}
    
    virtual void wyswietlInformacje() const=0;
    virtual int getId() const = 0;
    virtual std::string getTytul() const = 0;
};

#endif