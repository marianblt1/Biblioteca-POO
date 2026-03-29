#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>

class Carte {
private:
    std::string titlu;
    std::string autor;
    std::string ISBN;
    int anAparitie;
    std::string status;    // Disponibila / Imprumutata / Rezervata
    std::string stare;     // Noua / Buna / Uzata / Deteriorata
    int timpImprumut;      // in zile

public:
    // Constructor
    Carte(std::string titlu, std::string autor, std::string isbn, 
          int anAparitie, std::string stare, int timpImprumut);

    std::string getTitlu() const;
    std::string getAutor() const;
    std::string getISBN() const;
    int getAnAparitie() const;
    std::string getStatus() const;
    std::string getStare() const;
    int getTimpImprumut() const;

    void setStatus(std::string status);
    void setStare(std::string stare);

    virtual void afisareDetalii() const;

    // Destructor
    virtual ~Carte() {}
};

#endif