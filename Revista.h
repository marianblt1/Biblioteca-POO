#ifndef REVISTA_H
#define REVISTA_H

#include "Carte.h"

class Revista : public Carte {
private:
    int numar;                   // numarul editiei
    std::string periodicitate;   // Saptamanala / Lunara / Anuala

public:
    Revista(std::string titlu, std::string autor, std::string ISBN,
            int anAparitie, std::string stare, int timpImprumut,
            int numar, std::string periodicitate);

    int getNumar() const;
    std::string getPeriodicitate() const;

    void afisareDetalii() const override;

    virtual ~Revista() {}
};
#endif