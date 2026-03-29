#ifndef UTILIZATORCERCETATOR_H
#define UTILIZATORCERCETATOR_H

#include "Utilizator.h"

class UtilizatorCercetator : public Utilizator {
private:
    std::string domeniuCercetare;
    std::string institutie;

public:
    UtilizatorCercetator(std::string nume, std::string prenume, int id,
                         std::string email, std::string telefon,
                         std::string domeniuCercetare, std::string institutie);

    std::string getDomeniuCercetare() const;
    std::string getInstitutie() const;

    void afisareDetalii() const override;

    virtual ~UtilizatorCercetator() {}
};
#endif