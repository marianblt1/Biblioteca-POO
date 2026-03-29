// UtilizatorAdult.h
#ifndef UTILIZATORADULT_H
#define UTILIZATORADULT_H

#include "Utilizator.h"

class UtilizatorAdult : public Utilizator {
private:
    std::string ocupatie;

public:
    UtilizatorAdult(std::string nume, std::string prenume, int id,
                    std::string email, std::string telefon,
                    std::string ocupatie);

    std::string getOcupatie() const;

    void afisareDetalii() const override;

    virtual ~UtilizatorAdult() {}
};
#endif