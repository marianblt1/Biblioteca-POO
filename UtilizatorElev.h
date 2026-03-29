// UtilizatorElev.h
#ifndef UTILIZATORELEV_H
#define UTILIZATORELEV_H

#include "Utilizator.h"

class UtilizatorElev : public Utilizator {
private:
    std::string scoala;
    std::string clasa;

public:
    UtilizatorElev(std::string nume, std::string prenume, int id,
                   std::string email, std::string telefon,
                   std::string scoala, std::string clasa);

    std::string getScoala() const;
    std::string getClasa() const;

    void afisareDetalii() const override;

    virtual ~UtilizatorElev() {}
};
#endif