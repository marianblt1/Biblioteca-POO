#ifndef CARTEFIZICA_H
#define CARTEFIZICA_H

#include "Carte.h"

class CarteFizica : public Carte {
private:
    int nrExemplare;
    std::string localizare;  // raftul/sectiunea din biblioteca

public:
    CarteFizica(std::string titlu, std::string autor, std::string ISBN,
                int anAparitie, std::string stare, int timpImprumut,
                int nrExemplare, std::string localizare);

    int getNrExemplare() const;
    std::string getLocalizare() const;
    void setNrExemplare(int nr);

    virtual void afisareDetalii() const override;

    virtual ~CarteFizica() {}
};
#endif