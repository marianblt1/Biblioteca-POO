// UtilizatorPensionar.h
#ifndef UTILIZATORPENSIONAR_H
#define UTILIZATORPENSIONAR_H

#include "Utilizator.h"

class UtilizatorPensionar : public Utilizator {
private:
    int varstaPensionare;

public:
    UtilizatorPensionar(std::string nume, std::string prenume, int id,
                        std::string email, std::string telefon,
                        int varstaPensionare);

    int getVarstaPensionare() const;

    void afisareDetalii() const override;

    virtual ~UtilizatorPensionar() {}
};
#endif